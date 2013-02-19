#include <iostream>

#include "../include/YNetwork/YConnection.h"

/*!
 * \brief
 * �������ݲ��Է�����
 */
void recvData()
{
	int acceptPort = 0;
	std::cout<<"����������˿ں�:";
	std::cin>>acceptPort;

	//��ʼ���׽���
	WORD wVersionRequested = MAKEWORD(1,1);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested,&wsaData);
	if ( err != 0 ) 
	{
		WSACleanup();
		std::cout<<"��ʼ���׽���ʧ�ܣ�"<<std::endl;
		return;
	}

	//�����׽���
	SOCKET serverSocket = socket(AF_INET,SOCK_STREAM,0);
	if(INVALID_SOCKET == serverSocket)
	{
		WSACleanup();
		std::cout<<"�����׽���ʧ�ܣ�"<<std::endl;
		return;
	}

	//�󶨶˿�
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(acceptPort);

	err = bind(serverSocket,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	if(SOCKET_ERROR == err)
	{
		WSACleanup();
		std::cout<<"�󶨶˿�ʧ�ܣ�"<<std::endl;
		return;
	}

	//����������
	err = listen(serverSocket,200);
	if(SOCKET_ERROR == err)
	{
		WSACleanup();
		std::cout<<"������������ʧ�ܣ�"<<std::endl;
		return;
	}

	SOCKADDR_IN addrClient;//�Ϳͻ������ӵķ����׽���
	int len=sizeof(SOCKADDR);

	//��������
	std::cout<<"��������ѿ����������˿ںţ�"<<acceptPort<<"��"<<std::endl;
	SOCKET sockConn=accept(serverSocket,(SOCKADDR*)&addrClient,&len);

	YLR::YDataType::YByteType data;
	YLR::YNetWork::YConnection con;
	bool r = con.recaiveData(sockConn,data,50,1000,1000);
	if(r)
	{
		YBYTE * text = new YBYTE(data.getSize());
		data.getData(text,data.getSize());

		std::cout<<text<<std::endl;
		delete text;
	}
	else
	{
		std::cout<<"��������ʧ�ܣ�"<<std::endl;
	}

	closesocket(serverSocket);//�ر�����
    WSACleanup();
}

int main()
{
	YLR::YDataType::YByteType b;
	while(true)
	{
		int inputNum = 0; //�����ѡ����š�
		std::cout<<"YNetwork���Գ��������������������ѡ����Ҫ���еĲ�����"<<std::endl;
		std::cout<<"1�����ݽ��ա�"<<std::endl;
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
			recvData();
		}
		else
		{
			std::cout<<"���������Ų���ȷ�����������룡"<<std::endl;
		}
	}

	return 0;
}