#include <iostream>
#include <string>

#include "../include/YNetwork/YConnection.h"

/*!
 * \brief
 * �������ݲ��Է�����
 */
void sendData()
{
	std::string ip;
	int port;
	std::cout<<"�����������IP��";
	std::cin>>ip;
	if(ip == "")
	{
		ip = "127.0.0.1";
	}

	std::cout<<"����������������˿ڣ�";
	std::cin>>port;

	//�����׽���
	WORD wVersionRequested = MAKEWORD(1,1);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested,&wsaData);
	if ( err == 0 ) 
	{
		//���ӷ�����
		SOCKADDR_IN addrSrv;
		addrSrv.sin_addr.S_un.S_addr=inet_addr(ip.c_str());
		addrSrv.sin_family=AF_INET;
		addrSrv.sin_port=htons(port);

		std::string sendText;
		std::cout<<"��������Ҫ���͵����֣�";
		std::cin>>sendText;

		//�����׽���
		SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
		if(INVALID_SOCKET != sockClient)
		{
			err = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));

			if(SOCKET_ERROR != err)
			{
				std::cout<<"���ͷ�����ipΪ��"<<ip<<"���������˿�Ϊ��"<<port<<"��"<<std::endl;;

				YLR::YDataType::YByteType data((unsigned int)sendText.size() + 1,(const YBYTE *)sendText.c_str());

				YLR::YNetWork::YConnection con;
				bool r = con.sendData(sockClient,data,20,10000,10000);
				if(r)
				{
					std::cout<<"�������ݳɹ���"<<std::endl;
				}
				else
				{
					std::cout<<"��������ʧ�ܣ�"<<std::endl;
				}
			}
			else
			{
				std::cout<<"���ӷ�����ʧ�ܣ�"<<std::endl;
			}
		}
		else
		{
			std::cout<<"�����׽���ʧ�ܣ�"<<std::endl;
		}

		closesocket(sockClient);
		WSACleanup();
	}
}

int main()
{
	while(true)
	{
		int inputNum = 0; //�����ѡ����š�
		std::cout<<"YNetwork���Գ���ͻ�������������ѡ����Ҫ���еĲ�����"<<std::endl;
		std::cout<<"1�����ݷ��͡�"<<std::endl;
		std::cout<<"0���˳�����"<<std::endl;
		std::cout<<"����������ѡ��";
		std::cin>>inputNum;

		if(0 == inputNum)
		{
			std::cout<<"�����Ѿ��˳���"<<std::endl;
			break;
		}
		else if(1 == inputNum)
		{
			sendData();
		}
		else
		{
			std::cout<<"���������Ų���ȷ�����������룡"<<std::endl;
		}
	}

	return 0;
}