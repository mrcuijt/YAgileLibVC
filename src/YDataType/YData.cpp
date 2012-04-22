#include "..\..\include\YDataType\YData.h"

#include <memory.h>
#include <sstream>

using namespace YLR;

YData::YData() :
	_type(YData::YNull)
{
}

YData::YData(const int &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YInt;
}

YData::YData(const double &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YDouble;
}

YData::YData(const float &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YFloat;
}

YData::YData(const std::string &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YString;
}

YData::DatyType YData::getDataType() const
{
	return this->_type;
}

void YData::setNull()
{
	this->setSize();
	this->_type = YData::YNull;
}

void YData::setFrom(const int &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YInt;
}

void YData::setFrom(const double &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YDouble;
}

void YData::setFrom(const float &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YFloat;
}

void YData::setFrom(const std::string &d)
{
	//���ô洢�ռ�
	this->setSize(sizeof(d));

	//��������
	YBYTE * buf = new YBYTE[this->getSize()];
	memcpy(buf,&d,this->getSize());
	this->setData(buf,this->getSize());
	delete[] buf;
	this->_type = YData::YString;
}

int YData::toInt() const
{
	int data = 0;

	switch(this->_type)
	{
	case YData::YInt:
		{
			YBYTE * buf = new YBYTE[sizeof(int)];
			this->getData(buf,sizeof(int));
			memcpy(&data,buf,sizeof(int));
			delete[] buf;
			break;
		}
	case YData::YDouble:
		{
			YBYTE * buf = new YBYTE[sizeof(double)];
			this->getData(buf,sizeof(double));
			double d = 0;
			memcpy(&d,buf,sizeof(double));
			data = (int)d;
			delete[] buf;
			break;
		}
	case YData::YFloat:
		{
			YBYTE * buf = new YBYTE[sizeof(float)];
			this->getData(buf,sizeof(float));
			float d = 0;
			memcpy(&d,buf,sizeof(float));
			data = (int)d;
			delete[] buf;
			break;
		}
	case YData::YString:
		{
			YBYTE * buf = new YBYTE[this->getSize()];
			this->getData(buf,this->getSize());
			data = atoi((char *)buf);
			delete[] buf;
		}
	}

	return data;
}

double YData::toDouble() const
{
	double data = 0;

	switch(this->_type)
	{
	case YData::YInt:
		{
			YBYTE * buf = new YBYTE[sizeof(int)];
			this->getData(buf,sizeof(int));
			int d = 0;
			memcpy(&d,buf,sizeof(int));
			data = d;
			delete[] buf;
			break;
		}
	case YData::YDouble:
		{
			YBYTE * buf = new YBYTE[sizeof(double)];
			this->getData(buf,sizeof(double));
			memcpy(&data,buf,sizeof(double));
			delete[] buf;
			break;
		}
	case YData::YFloat:
		{
			YBYTE * buf = new YBYTE[sizeof(float)];
			this->getData(buf,sizeof(float));
			float d = 0;
			memcpy(&d,buf,sizeof(float));
			data = d;
			delete[] buf;
			break;
		}
	case YData::YString:
		{
			YBYTE * buf = new YBYTE[this->getSize()];
			this->getData(buf,this->getSize());
			data = atof((char *)buf);
			delete[] buf;
		}
	}

	return data;
}

float YData::toFloat() const
{
	float data = 0;

	switch(this->_type)
	{
	case YData::YInt:
		{
			YBYTE * buf = new YBYTE[sizeof(int)];
			this->getData(buf,sizeof(int));
			int d = 0;
			memcpy(&d,buf,sizeof(int));
			data = (float)d;
			delete[] buf;
			break;
		}
	case YData::YDouble:
		{
			YBYTE * buf = new YBYTE[sizeof(double)];
			this->getData(buf,sizeof(double));
			double d = 0;
			memcpy(&d,buf,sizeof(double));
			data = (float)d;
			delete[] buf;
			break;
		}
	case YData::YFloat:
		{
			YBYTE * buf = new YBYTE[sizeof(float)];
			this->getData(buf,sizeof(float));
			memcpy(&data,buf,sizeof(float));
			delete[] buf;
			break;
		}
	case YData::YString:
		{
			YBYTE * buf = new YBYTE[this->getSize()];
			this->getData(buf,this->getSize());
			data = (float)atof((char *)buf);
			delete[] buf;
		}
	}

	return data;
}

std::string YData::toString() const
{
	std::string data = "";

	switch(this->_type)
	{
	case YData::YInt:
		{
			YBYTE * buf = new YBYTE[sizeof(int)];
			this->getData(buf,sizeof(int));
			int d = 0;
			memcpy(&d,buf,sizeof(int));
			std::stringstream stream;
			stream << d;
			stream >> data;
			delete[] buf;
			break;
		}
	case YData::YDouble:
		{
			YBYTE * buf = new YBYTE[sizeof(double)];
			this->getData(buf,sizeof(double));
			double d = 0;
			memcpy(&d,buf,sizeof(double));
			std::stringstream stream;
			stream << d;
			stream >> data;
			delete[] buf;
			break;
		}
	case YData::YFloat:
		{
			YBYTE * buf = new YBYTE[sizeof(float)];
			this->getData(buf,sizeof(float));
			float d = 0;
			memcpy(&d,buf,sizeof(float));
			std::stringstream stream;
			stream << d;
			stream >> data;
			delete[] buf;
			break;
		}
	case YData::YString:
		{
			YBYTE * buf = new YBYTE[this->getSize()];
			this->getData(buf,this->getSize());
			data.assign((char *)buf);
			delete[] buf;
		}
	}

	return data;
}