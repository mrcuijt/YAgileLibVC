#include "../../include/YDataBase/YColumn.h"

using namespace YLR;

YColumn::YColumn() :
	_physicaName(NULL),
	_logicalName(NULL),
	_dataType(YData::YInt)
{
	//��ʼ�����ݡ�
}

YColumn::YColumn(const std::string & physicaName, const std::string & logicalName, const YData::DataType & dataType)
{
	//ʹ�ò�����ʼ����
	this->_physicaName = new std::string(physicaName);
	this->_logicalName = new std::string(logicalName);
	this->_dataType = dataType;
}

YColumn::YColumn(const YColumn & item)
{
	//ʹ�ö����ʼ�����ݡ�
	this->_physicaName = new std::string(*item._physicaName);
	this->_logicalName = new std::string(*item._logicalName);
	this->_dataType = item._dataType;
}

YColumn::~YColumn()
{
	//�ͷŶ���������Դ��
	if(this->_physicaName != NULL)
	{
		delete this->_physicaName;
	}

	if(this->_logicalName != NULL)
	{
		delete this->_logicalName;
	}
}

YColumn & YColumn::operator=(const YColumn & item)
{
	//�ͷ�ԭ����Դ
	if(this->_physicaName != NULL)
	{
		delete this->_physicaName;
	}

	if(this->_logicalName != NULL)
	{
		delete this->_logicalName;
	}

	this->_physicaName = new std::string(*item._physicaName);
	this->_logicalName = new std::string(*item._logicalName);
	this->_dataType = item._dataType;

	return *this;
}

void YColumn::setPhysicaName(const std::string & physicaName)
{
	//�ͷ�ԭ�пռ�
	if(this->_physicaName != NULL)
	{
		delete this->_physicaName;
	}
	this->_physicaName = new std::string(physicaName);
}

const std::string * YColumn::getPhysicaName() const
{
	return this->_physicaName;
}

void YColumn::setLogicalName(const std::string & logicalName)
{
	//�ͷ�ԭ�пռ�
	if(this->_logicalName != NULL)
	{
		delete this->_logicalName;
	}
	this->_logicalName = new std::string(logicalName);
}

const std::string * YColumn::getLogicalName() const
{
	return this->_logicalName;
}

void YColumn::setDataType(const YData::DataType & dataType)
{
	this->_dataType = dataType;
}

const YData::DataType YColumn::getDataType() const
{
	return this->_dataType;
}