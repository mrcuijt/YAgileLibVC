// YSerialPort.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "YSerialPortPro.h"


// ���ǵ���������һ��ʾ��
YSERIALPORT_API int nYSerialPort=0;

// ���ǵ���������һ��ʾ����
YSERIALPORT_API int fnYSerialPort(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� YSerialPort.h
CYSerialPortPro::CYSerialPortPro()
{
	return;
}
