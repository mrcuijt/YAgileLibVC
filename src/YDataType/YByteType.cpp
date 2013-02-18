#include <stdio.h>

#include "..\..\include\YDataType\YByteType.h"

using namespace YLR;
using namespace YDataType;

YByteType::YByteType(const unsigned int &count, const YBYTE * initData)
	:_data(NULL),_size(0)
{
	//�����洢�ռ䣬�����СΪ0�򲻴���
	if(count > 0)
	{
		this->_data = new YBYTE[count];
		this->_size = count;

		//��ʼ���ӳ��ռ����ݣ�δָ����ʼ���������ʼ����0x00��
		if(initData != NULL)
		{
			for(unsigned int i = 0;i < count;i++)
			{
				*(this->_data + i) = *(initData + i);
			}
		}
	}
}

YByteType::YByteType(const YByteType &item)
{
	////�ͷ�ԭ����
	//if(this->_size > 0)
	//{
	//	delete[] this->_data;
	//}

	//�����¿ռ�
	if(item._data != NULL && item._size > 0)
	{
		this->_data = new YBYTE[item._size];
		this->_size = item._size;

		//��������
		for(unsigned int i = 0;i < item._size;i++)
		{
			*(this->_data + i) = *(item._data + i);
		}
	}
	else
	{
		this->_data = NULL;
		this->_size = 0;
	}
}

YByteType::~YByteType()
{
	if(this->_data != NULL)
	{
		delete[] this->_data;
	}
}

bool YByteType::setSize(const unsigned int &count)
{
	if(count > 0)
	{
		//���������ݿռ�
		YBYTE * buffer = new YBYTE[count];

		//��������
		if(this->_size >= count)
		{
			for(unsigned int i = 0;i < count;i++)
			{
				*(buffer + i) = *(this->_data + i);
			}
		}
		else
		{
			for(unsigned int i = 0;i < this->_size;i++)
			{
				*(buffer + i) = *(this->_data + i);
			}
		}

		//���ԭ����
		delete[] this->_data;
		this->_data = buffer;
		this->_size = count;
	}
	else
	{
		//�ͷ�ԭ���ݿռ�
		delete[] this->_data;
		this->_data = NULL;
		this->_size = count;
	}
	return true;
}

unsigned int YByteType::getSize() const
{
	return this->_size;
}

unsigned int YByteType::setData(const YBYTE &data, const unsigned int &location)
{
	if(this->_size > location)
	{
		*(this->_data + location) = data;
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int YByteType::setData(const YBYTE * data, const unsigned int &count, const unsigned int &location)
{
	if(this->_size >= location + count)
	{
		for(unsigned int i = 0;i < count;i++)
		{
			*(this->_data + location + i) = *(data + i);
		}
		return count;
	}
	else
	{
		for(unsigned int i = 0;i < this->_size;i++)
		{
			*(this->_data + location + i) = *(data + i);
		}
		return this->_size - location;
	}
}

unsigned int YByteType::getData(YBYTE &data, const unsigned int &location) const
{
	if(location < this->_size)
	{
		data = *(this->_data + location);
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int YByteType::getData(YBYTE * data, const unsigned int &count, const unsigned int &location) const
{
	if(this->_size >= location + count)
	{
		for(unsigned int i = location;i < (location + count);i++)
		{
			*(data + i - location) = *(this->_data + i);
		}
		return count;
	}
	else
	{
		for(unsigned int i = location;i < this->_size;i++)
		{
			*(data + i) = *(this->_data + i);
		}
		return this->_size - location;
	}
}

YByteType & YByteType::operator=(const YByteType &item)
{
	//�ͷ�ԭ����
	if(this->_data != NULL)
	{
		delete[] this->_data;
	}

	//�����¿ռ�
	if(item._data != NULL && item._size > 0)
	{
		this->_data = new YBYTE[item._size];
		this->_size = item._size;

		//��������
		for(unsigned int i = 0;i < item._size;i++)
		{
			*(this->_data + i) = *(item._data + i);
		}
	}
	else
	{
		this->_data = NULL;
		this->_size = 0;
	}

	return *this;
}