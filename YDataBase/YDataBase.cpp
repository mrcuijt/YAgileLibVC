// YDataBase.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "YDataBase.h"


// ���ǵ���������һ��ʾ��
YDATABASE_API int nYDataBase=0;

// ���ǵ���������һ��ʾ����
YDATABASE_API int fnYDataBase(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� YDataBase.h
CYDataBase::CYDataBase()
{
	return;
}
