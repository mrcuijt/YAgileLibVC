#include "../../include/YNetwork/YConnection.h"

using namespace YLR;
using namespace YNetWork;

YConnection::YConnection() :
	_isAccept(false),
	_isAcceptMutex(CreateMutex(NULL,FALSE,NULL)),
	_acceptIsOut(true),
	_acceptIsOutMutex(CreateMutex(NULL,FALSE,NULL)),
	_serverSocket(NULL)
{
}

void YConnection::startAccept(const int &port,AcceptFunction f,const int &connectCount,const bool &mode)
{
	if(WAIT_OBJECT_0 == WaitForSingleObject(this->_isAcceptMutex,INFINITE)
		&& WAIT_OBJECT_0 == WaitForSingleObject(this->_acceptIsOutMutex,INFINITE))
	{
		this->_acceptIsOut = false; //������������û���˳�
		//��ʼ���׽���
		WORD wVersionRequested = MAKEWORD(1,1);
		WSADATA wsaData;
		int err = WSAStartup(wVersionRequested,&wsaData);
		if ( err != 0 ) 
		{
			WSACleanup();
			return;
		}

		//�����׽���
		this->_serverSocket = socket(AF_INET,SOCK_STREAM,0);
		if(INVALID_SOCKET == this->_serverSocket)
		{
			WSACleanup();
			return;
		}

		//�󶨶˿�
		SOCKADDR_IN addrSrv;
		addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(port);

		err = bind(this->_serverSocket,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
		if(SOCKET_ERROR == err)
		{
			WSACleanup();
			return;
		}

		//����������
		err = listen(this->_serverSocket,connectCount);
		if(SOCKET_ERROR == err)
		{
			WSACleanup();
			return;
		}

		SOCKADDR_IN addrClient;//�Ϳͻ������ӵķ����׽���
		int len = sizeof(SOCKADDR);

		//���ü���ģʽ
		u_long iMode = 1;
		if(mode)
		{
			iMode = 0;
		}
		ioctlsocket(this->_serverSocket, FIONBIO,&iMode);
		
		//��������
		this->_isAccept = true;
		ReleaseMutex(this->_isAcceptMutex);
		ReleaseMutex(this->_acceptIsOutMutex);

		while(this->_isAccept)
		{
			SOCKET sockConn = accept(this->_serverSocket,(SOCKADDR*)&addrClient,&len);

			if(INVALID_SOCKET != sockConn)
			{
				(*f)(sockConn);
			}
		}

		if(WAIT_OBJECT_0 == WaitForSingleObject(this->_acceptIsOutMutex,INFINITE))
		{
			this->_acceptIsOut = true; //���������Ѿ��˳���
		}
	}
}

bool YConnection::stopAccept()
{
	bool retValue = false;

	//����ֹͣ���
	if(WAIT_OBJECT_0 == WaitForSingleObject(this->_isAcceptMutex,INFINITE))
	{
		this->_isAccept = false;
		closesocket(this->_serverSocket);//�ر�����
		WSACleanup();
		ReleaseMutex(this->_isAcceptMutex);
	}
	
	//�жϳ����Ƿ��˳���
	int iCount = 0; //ѭ���ȴ�������
	while(true)
	{
		if(WAIT_OBJECT_0 == WaitForSingleObject(this->_acceptIsOutMutex,100))
		{
			if(this->_acceptIsOut)
			{
				retValue = true;
				break;
			}
			iCount++;
			if(iCount > 600)
			{
				break;
			}
			ReleaseMutex(this->_acceptIsOutMutex);
		}
	}

	return retValue;
}

bool YConnection::isStarted()
{
	bool retValue = false;
	if(WAIT_OBJECT_0 == WaitForSingleObject(this->_isAcceptMutex,INFINITE))
	{
		retValue = this->_isAccept;
		ReleaseMutex(this->_isAcceptMutex);
	}
	return retValue;
}

inline bool YConnection::setRcvTimeOut(SOCKET s,const int &t)
{
	int z = setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char *)&t,sizeof(int));

	if(z)
		return false;  //ʧ��
	else
		return true;   //�ɹ�
}

inline int YConnection::getRcvTimeOut(SOCKET s)
{
	int rcvbuf = 0;
	int optlen = sizeof(int);
	int z = getsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char *)&rcvbuf,&optlen);

	if(z)
		return -1;
	else
		return rcvbuf;
}

inline bool YConnection::setSndTimeOut(SOCKET s,const int &t)
{
	int z = setsockopt(s,SOL_SOCKET,SO_SNDTIMEO,(char *)&t,sizeof(int));

	if(z)
		return false;  //ʧ��
	else
		return true;   //�ɹ�
}

inline int YConnection::getSndTimeOut(SOCKET s)
{
	int rcvbuf = 0;
	int optlen = sizeof(int);
	int z = getsockopt(s,SOL_SOCKET,SO_SNDTIMEO,(char *)&rcvbuf,&optlen);

	if(z)
		return -1;
	else
		return rcvbuf;
}

bool YConnection::sendData(SOCKET s,const YDataType::YByteType &data,const int &packageLength,const int &sndTimeOut,const int &rcvTimeOut)
{
	bool retValue = true;; //����ֵ
	//��ʼ���׽���
	YConnection::setSndTimeOut(s,sndTimeOut);
	YConnection::setRcvTimeOut(s,rcvTimeOut);

	//����������
	YBYTE reqData[14];
	memset(reqData,0,14);
	reqData[0] = YConnection::SendData;
	int i = 1;
	memcpy(reqData + 1,&i,4);
	memcpy(reqData + 5,&i,4);
	i = 0;
	memcpy(reqData + 9,&i,4);
	reqData[13] = YConnection::EndFlag;

	int r = send(s,(const char *)reqData,14,0);
	if(SOCKET_ERROR != r)
	{
		//�����������նԷ��ظ�
		r = recv(s,(char *)reqData,14,0);
		if(SOCKET_ERROR != r)
		{
			if(YConnection::Yes == reqData[0])
			{
				//��������
				YBYTE * buf = new YBYTE[packageLength + 14];
				buf[0] = YConnection::DataPackage;

				//�������ݰ�����
				int packageCount = data.getSize() / packageLength;
				if(data.getSize() % packageLength > 0)
				{
					packageCount++;
				}
				memcpy(buf + 1,&packageCount,4);

				buf[packageLength + 13] = YConnection::EndFlag;//

				int sendLength = 0; //�������ݼ���
				while(data.getSize() - sendLength > 0)
				{
					//��ʼ�����е����ݲ���
					memset(buf + 13,0,packageLength);

					//��ǰ���ݰ����
					int packageOrder = sendLength / packageLength + 1;
					memcpy(buf + 5,&packageOrder,4);

					int l = 0;
					if(data.getSize() - sendLength >= (unsigned int)packageLength)
					{
						l = packageLength;
						data.getData(buf + 13,l,sendLength);
						sendLength += l;
					}
					else
					{
						l = data.getSize() - sendLength;
						data.getData(buf + 13,l,sendLength);
						sendLength += l;
					}
					//���ݰ������ݳ���
					memcpy(buf + 9,&l,4);

					r = send(s,(const char *)buf,l + 14,0);

					if(SOCKET_ERROR != r)
					{
						r = recv(s,(char *)reqData,14,0);
						if(SOCKET_ERROR != r)
						{
							if(YConnection::Go != reqData[0])
							{
								//�Է������������������
								retValue = false;
								break;
							}
						}
						else
						{
							//�������ݰ�����նԷ��ظ�ʧ��
							retValue = false;
							break;
						}
					}
					else
					{
						//���ݰ�����ʧ��
						retValue = false;
						break;
					}
				}

				delete[] buf;
			}
			else
			{
				//�Է�������������
				retValue = false;
			}
		}
		else
		{
			//����������ʱ���նԷ��ظ�
			retValue = false;
		}
	}
	else
	{
		//������������ʧ��
		retValue = false;
	}

	//�������
	//����������
	YBYTE endReqData[14];
	memset(endReqData,0,14);
	endReqData[0] = YConnection::End;
	i = 1;
	memcpy(endReqData + 1,&i,4);
	memcpy(endReqData + 5,&i,4);
	i = 0;
	memcpy(endReqData + 9,&i,4);
	endReqData[13] = YConnection::EndFlag;

	send(s,(const char *)endReqData,14,0);

	return retValue;
}

bool YConnection::recaiveData(SOCKET s,YDataType::YByteType &data,const int &bufLength,const int &sndTimeOut,const int &rcvTimeOut)
{
	bool retValue = false;
	//��ʼ���׽���
	YConnection::setSndTimeOut(s,sndTimeOut);
	YConnection::setRcvTimeOut(s,rcvTimeOut);

	YBYTE * rcvBuf = new YBYTE[bufLength]; //�������ݻ�������
	memset(rcvBuf,0,bufLength);

	//��������
	int r = recv(s,(char *)rcvBuf,bufLength,0);
	if(SOCKET_ERROR != r)
	{
		if(YConnection::SendData == rcvBuf[0])
		{
			YBYTE resData[14]; //��Ӧ����
			resData[0] = YConnection::Yes;
			int i = 1;
			memcpy(resData + 1,&i,4);
			memcpy(resData + 5,&i,4);
			i = 0;
			memcpy(resData + 9,&i,4);
			resData[13] = YConnection::EndFlag;

			//������
			r = send(s,(const char *)resData,14,0);
			if(SOCKET_ERROR != r)
			{
				//��ʼ��������
				data.setSize(0);
				while(true)
				{
					memset(rcvBuf,0,bufLength); //��ʼ��������
					r = recv(s,(char *)rcvBuf,bufLength,0);
					if(SOCKET_ERROR != r)
					{
						if(YConnection::DataPackage == rcvBuf[0])
						{
							int packageLength = 0; //���ݰ������ݳ���
							memcpy(&packageLength,rcvBuf + 9,4);
							if(packageLength > 0)
							{
								data.setSize(data.getSize() + packageLength);
								data.setData(rcvBuf + 13,packageLength,data.getSize() - packageLength);
							}

							//������������
							resData[0] = YConnection::Go;
							r = send(s,(const char *)resData,14,0);
							if(SOCKET_ERROR == r)
							{
								//��������������Ӧʧ��
								break;
							}
						}
						else if(YConnection::End == rcvBuf[0])
						{
							//����������ɡ�
							retValue = true;
							break;
						}
						else
						{
							//���յ������ݲ������ݰ������ͳ�����Ӧ��ֹͣ���ա�
							resData[0] = YConnection::Error;
							send(s,(const char *)resData,14,0);
							break;
						}
					}
					else
					{
						//��������ʧ��
						break;
					}
				}
			}//������������Ӧʧ��
		}//�ж�����λΪ������������
	}//������������

	delete[] rcvBuf;
	return retValue;
}