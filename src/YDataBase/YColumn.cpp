#include "../../include/YDataBase/YColumn.h"

using namespace YLR;

YColumn::YColumn() :
	_physicaName(new std::string()),
	_logicalName(new std::string())
{
	//��ʼ�����ݡ�
}

YColumn::YColumn(const std::string & physicaName, const std::string & logicalName, const YData::DataType & dataType)
{
	//ʹ�ò�����ʼ����
	this->_physicaName = new std::string(physicaName);
	this->_logicalName = new std::string(logicalName);
}

YColumn::YColumn(const YColumn & item)
{
	//ʹ�ö����ʼ�����ݡ�
	this->_physicaName = new std::string(*item._physicaName);
	this->_logicalName = new std::string(*item._logicalName);
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