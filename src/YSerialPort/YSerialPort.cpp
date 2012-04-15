#include "..\..\include\YSerialPort\YSerialPort.h"

using namespace YLR;

YSerialPort::YSerialPort(void) : 
	serialNum(1),
	baudRate(9600),
	byteSize(8),
	parity(NoParity),
	stopBits(OneStopBit),
	serialPort(NULL)
{

}

YSerialPort::~YSerialPort(void)
{
	this->closeSerialPort();
}

bool YSerialPort::openSerialPort(void)
{
	//���ɴ��ں�
	//LPCTSTR com;

#ifdef UNICODE
	WCHAR a[8];
	memset(a,'\0',sizeof(a));
	wsprintf(a,L"COM%d:",this->serialNum);
	//com = a;
#else
	CHAR a[8];
	memset(a,'\0',sizeof(a));
	sprintf(a,L"COM%d:",this->serialNum);
	//com = a;
#endif

	//�򿪴���
	this->serialPort = CreateFile(a,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
	if(this->serialPort == NULL)
	{
		return false;
	}

	//���ô���
	DCB  PortDCB;
	PortDCB.DCBlength = sizeof(DCB);
	GetCommState(this->serialPort,&PortDCB);
	PortDCB.BaudRate = this->baudRate;
	PortDCB.ByteSize = this->byteSize;
	PortDCB.Parity = this->parity; 
	PortDCB.StopBits = this->stopBits;  
	if (!SetCommState(this->serialPort, &PortDCB))
	{
		return false;
	}

	//���ó�ʱֵ
	COMMTIMEOUTS  CommTimeouts;
	GetCommTimeouts(this->serialPort, &CommTimeouts);
	CommTimeouts.ReadIntervalTimeout = 1000;  
	CommTimeouts.ReadTotalTimeoutMultiplier = 50;  
	CommTimeouts.ReadTotalTimeoutConstant = 100;    
	CommTimeouts.WriteTotalTimeoutMultiplier = 50;  
	CommTimeouts.WriteTotalTimeoutConstant = 100;    
	if (!SetCommTimeouts(this->serialPort, &CommTimeouts))
	{
		return false;
	}         

	return true;
}

int YSerialPort::sendData(const unsigned char * data, const int & count)
{
	if(this->serialPort != NULL)
	{
		//��մ��ڻ�����
		if(!PurgeComm(this->serialPort,PURGE_TXCLEAR))
		{
			return -3;
		}

		if(!PurgeComm(this->serialPort,PURGE_RXCLEAR))
		{
			return -4;
		}

		unsigned long int numBytes = 0; //���͵��ֽ���
		if(WriteFile (this->serialPort, // ���
			data, // ���ݻ�������ַ
			count, // ��������
			&numBytes, // ���ط��ͳ�ȥ���ֽ���
			NULL // ��֧���ص�
			))

		{
			return numBytes;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return -1;
	}
}

int YSerialPort::receiveDate(unsigned char * data, const int & count)
{
	if(this->serialPort != NULL)
	{
		unsigned long int numBytes = 0; //���յ��ֽ���

		SetCommMask(this->serialPort, EV_RXCHAR); //ֻ�����ַ�

		if(ReadFile(this->serialPort, data, count, &numBytes, 0))
		{
			return numBytes;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return -1;
	}
}

bool YSerialPort::closeSerialPort(void)
{
	if(this->serialPort != NULL)
	{
		if(CloseHandle(this->serialPort))
		{
			this->serialPort = NULL;
		}
		else
		{
			return false;
		}
	}
	return true;
}
