#include "../../include/YDataBase/YSQLiteDataBase.h"
#include "../../include/YDataType/YTextEncode.h"

using namespace YLR;
using namespace YDataBase;

YSQLiteDataBase::YSQLiteDataBase() :
	_databaseType(YDataInterface::SQLite),
	_filePath(new std::string("")),
	_errorText(new std::string("")),
	_connectState(YDataInterface::Disconnected)
{
}

YSQLiteDataBase::YSQLiteDataBase(const YSQLiteDataBase & item)
{
	this->_databaseType = item._databaseType;
	this->_connectState = YDataInterface::Disconnected;
	this->_filePath = new std::string(*item._filePath);
	this->_errorText = new std::string(*item._errorText);
}

YSQLiteDataBase::~YSQLiteDataBase()
{
	delete this->_filePath;
	delete this->_errorText;
}

YSQLiteDataBase & YSQLiteDataBase::operator=(const YSQLiteDataBase & item)
{
	this->_databaseType = item._databaseType;
	this->_connectState = YDataInterface::Disconnected;
	this->_filePath = new std::string(*item._filePath);
	this->_errorText = new std::string(*item._errorText);

	return *this;
}

void YSQLiteDataBase::setFilePath(const std::string & path)
{
	*this->_filePath = path;
}

const std::string * YSQLiteDataBase::getFilePath() const
{
	return this->_filePath;
}

YDataInterface::DataBaseType YSQLiteDataBase::databaseType()
{
	return this->_databaseType;
}

const std::string * YSQLiteDataBase::errorMessage()
{
	return this->_errorText;
}

bool YSQLiteDataBase::connectDataBase()
{
	int rc = sqlite3_open(this->_filePath->c_str(),&this->_db);

	if(rc)
	{
		sqlite3_close(this->_db);
		*this->_errorText = "�����ݿ�ʧ�ܣ�||" + std::string(sqlite3_errmsg(this->_db));
		return false;
	}
	else
	{
		this->_connectState = YDataInterface::Connected;
		return true;
	}
}

bool YSQLiteDataBase::disconnectDataBase()
{
	int rc = sqlite3_close(this->_db);

	if(rc)
	{
		return false;
	}
	else
	{
		this->_connectState = YDataInterface::Disconnected;
		return true;
	}
		
}

YDataInterface::ConnectState YSQLiteDataBase::connectState()
{
	return this->_connectState;
}

bool YSQLiteDataBase::beginTransaction()
{
	char * zErr;
	int rc = sqlite3_exec(this->_db,"BEGIN",NULL,NULL,&zErr);

	if(rc)
	{
		*this->_errorText = "��������ʧ�ܣ�||" + std::string(zErr);
		sqlite3_free(zErr);
		return false;
	}
	else
	{
		return true;
	}
}

bool YSQLiteDataBase::commitTransaction()
{
	char * zErr;
	int rc = sqlite3_exec(this->_db,"COMMIT",NULL,NULL,&zErr);

	if(rc)
	{
		*this->_errorText = "�ύ����ʧ�ܣ�||" + std::string(zErr);
		sqlite3_free(zErr);
		return false;
	}
	else
	{
		return true;
	}
}

bool YSQLiteDataBase::rollbackTransaction()
{
	char * zErr;
	int rc = sqlite3_exec(this->_db,"ROLLBACK",NULL,NULL,&zErr);

	if(rc)
	{
		*this->_errorText = "�ع�����ʧ�ܣ�||" + std::string(zErr);
		sqlite3_free(zErr);
		return false;
	}
	else
	{
		return true;
	}
}

const YDataTable * YSQLiteDataBase::executeSqlReturnDt(const std::string & sql)
{
	YDataTable *table = NULL;
	sqlite3_stmt *stmt;

	int rc = sqlite3_prepare_v2(this->_db,sql.c_str(),strlen(sql.c_str()),&stmt,NULL);
	if(rc)
	{
		*this->_errorText = "��ȡ����ʧ�ܣ�||" + std::string(sqlite3_errmsg(this->_db));
	}
	else
	{
		table = new YDataTable();

		int columnCount = sqlite3_column_count(stmt);
		for(int i = 0;i < columnCount;i++)
		{
			YColumn column;
			column.setPhysicaName(std::string(sqlite3_column_name(stmt,i)));//���ݿ�洢�������ơ�
			table->addColumn(column);
		}

		rc = sqlite3_step(stmt);
		while(rc == SQLITE_ROW)
		{
			YDataRow row;
			for(int i = 0;i < columnCount;i++)
			{	
				row.addColumn(*table->getColumn(i));

				switch(sqlite3_column_type(stmt,i))
				{
				case SQLITE_INTEGER:
					{
						row.setData(i,YDataType::YData(sqlite3_column_int(stmt,i)));
						break;
					}
				case SQLITE_FLOAT:
					{
						row.setData(i,YDataType::YData(sqlite3_column_double(stmt,i)));
						break;
					}
				case SQLITE_TEXT:
					{
						std::string * text = YLR::YDataType::YTextEncode::utf8ToMultibyte(std::string((char *)sqlite3_column_text(stmt,i)));
						if(text != NULL)
						{
							row.setData(i,YDataType::YData(*text));
							YLR::YDataType::YTextEncode::freeText(text);
						}
						break;
					}
				case SQLITE_NULL:
				default:
					{
						YDataType::YData data;
						data.setNull();
						row.setData(i,data);
						break;
					}
				}
			}
			table->addRow(row);
			rc = sqlite3_step(stmt);
		}
	}

	return table;
}

bool YSQLiteDataBase::executeSqlWithOutDt(const std::string & sql)
{
	char *zErr;

	std::string * utf8Sql = YDataType::YTextEncode::multibyteToUtf8(sql);
	if(utf8Sql != NULL)
	{
		int rc = sqlite3_exec(this->_db,utf8Sql->c_str(),NULL,NULL,&zErr);
		YDataType::YTextEncode::freeText(utf8Sql);

		if(rc != SQLITE_OK)
		{
			*this->_errorText = "ִ�����ʧ�ܣ�||" + std::string(zErr);
			sqlite3_free(zErr);
			return false;
		}
		else
			return true;
	}
	else
	{
		*this->_errorText = "ִ�������뼯ת��ʧ�ܣ��Ӷ��ֽ�ת����utf8����";
		return false;
	}
}