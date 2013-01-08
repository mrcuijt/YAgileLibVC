#ifndef Y_SQLSERVER_DATABASE
#define Y_SQLSERVER_DATABASE

#include "YDataInterface.h"

namespace YLR
{
	/*!
	 * \brief
	 * SqlServer���ݿ�����࣬��������SqlServer���ݿ⡣
	 * ���ݿ����ʱʹ��΢��ADO��ע���ʼ��COM�����
	 * ���ߣ���˧ ����ʱ�䣺2013-1-8 9:43:09
	 */
	class YDATABASE_API YSqlServerDataBase : public YDataInterface
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 */
		YSqlServerDataBase();

		/*!
		 * \brief
		 * �������캯����
		 */
		YSqlServerDataBase(const YSqlServerDataBase & item);

		/*!
		 * \brief
		 * ����������
		 */
		~YSqlServerDataBase();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 */
		YSqlServerDataBase & operator=(const YSqlServerDataBase & item);

		/*!
		 * \brief
		 * �������ݿ����ơ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:21:38
		 * 
		 * \param name ���ݿ����ơ�
		 */
		void setDataBaseName(const std::string & name);

		/*!
		 * \brief
		 * ��ȡ���ݿ����ơ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:30:27
		 *
		 * return ���ݿ����ơ�
		 */
		const std::string * getDataBaseName() const;

		/*!
		 * \brief
		 * ���÷��������ơ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:32:02
		 * 
		 * \param name ���������ơ�
		 */
		void setServerName(const std::string & name);

		/*!
		 * \brief
		 * ��ȡ���������ơ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:33:30
		 *
		 * \return ���������ơ�
		 */
		const std::string * getServerName() const;

		/*!
		 * \brief
		 * �������ݿ�˿ںš�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:35:46
		 * 
		 * \param port �˿ںš�
		 */
		void setPort(const int & port);

		/*!
		 * \brief
		 * ��ȡ�˿ںš�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:37:27
		 *
		 * \return �˿ں�
		 */
		int getPort() const;

		/*!
		 * \brief
		 * ����ʵ������
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:38:47
		 *
		 * \param example ʵ������
		 */
		void setExample(const std::string & example);

		/*!
		 * \brief
		 * ��ȡʵ������
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 11:40:08
		 *
		 * \return ʵ������
		 */
		const std::string * getExample() const;

		/*!
		 * \brief
		 * �������ݿ�����û�id��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:41:34
		 *
		 * \param id �û�id
		 */
		void setUserID(const std::string & id);

		/*!
		 * \brief
		 * ��ȡ���ݿ�����û�id��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:43:02
		 *
		 * \return �û�id��
		 */
		const std::string * getUserID() const;

		/*!
		 * \brief
		 * �������ݿ��û��������롣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:44:33
		 *
		 * \param pass �������롣
		 */
		void setUserPassword(const std::string & pass);

		/*!
		 * \brief
		 * ��ȡ���ݿ��û��������롣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:46:00
		 *
		 * \return �û��������롣
		 */
		const std::string * getUserPassword() const;

		/*!
		 * \brief
		 * ��ȡ���ݿ����͡�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:47:47
		 *
		 * \return ���ݿ����͡�
		 */
		virtual DataBaseType databaseType();

		/*!
		 * \brief
		 * ��ȡ�ϴβ����Ĵ�����Ϣ��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:48:58
		 *
		 * \return ������Ϣ��
		 */
		virtual const std::string * errorMessage();

		/*!
		 * \brief
		 * �������ݿ⡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:50:36
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool connectDataBase();

		/*!
		 * \brief
		 * �Ͽ����ݿ����ӡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:51:10
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool disconnectDataBase();

		/*!
		 * \brief
		 * ��ȡ����״̬��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:51:45
		 *
		 * \return ����ת̨��
		 */
		virtual ConnectState connectState();

		/*!
		 * \brief
		 * �������ݿ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:52:25
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool beginTransaction();

		/*!
		 * \brief
		 * �ύ����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:53:45
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool commitTransaction();

		/*!
		 * \brief
		 * �ع�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:54:50
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool rollbackTransaction();

		/*!
		 * \brief
		 * ʵ��SQL��䣬�������ݣ�ʹ�ý���ע���ͷ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:55:19
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �������ݣ�ʧ�ܷ���NULL��
		 */
		virtual YDataTable * executeSqlReturnDt(const std::string & sql);

		/*!
		 * \brief
		 * ִ��û�����ݷ��ص�sql��䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-8 13:56:03
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool executeSqlWithOutDt(const std::string & sql);
	private:
		DataBaseType _dataBaseType; /*!< ���ݿ����͡� */
		ConnectState _connectState; /*!< ����״̬�� */
		std::string * _errorText; /*!< ���һ�β����Ĵ�����Ϣ�� */

		std::string * _dataBaseName; /*!< ���ݿ����ơ� */
		std::string * _serverName; /*!< ���������ơ� */
		int _port; /*!< �˿ںš� */
		std::string * _example; /*!< ʵ�����ơ� */
		std::string * _userID; /*!< �û�id�� */
		std::string * _userPassword; /*!< �û����롣 */
	};
}

#endif