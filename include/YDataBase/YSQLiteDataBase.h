#ifndef Y_SQLITE_DATABASE
#define Y_SQLITE_DATABASE

#include "YDataInterface.h"
#include "../../sqlite3/sqlite3.h"

namespace YLR
{
	/*!
	 * \brief
	 * SQLite���ݿ�����ࡣ
	 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:16:46
	 */
	class YSQLiteDataBase : public  YDataInterface
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 */
		YSQLiteDataBase();

		/*!
		 * \brief
		 * �������캯����
		 */
		YSQLiteDataBase(const YSQLiteDataBase & item);

		/*!
		 * \brief
		 * ����������
		 */
		~YSQLiteDataBase();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 */
		YSQLiteDataBase & operator=(const YSQLiteDataBase & item);
		
		/*!
		 * \brief
		 * �����ļ�·����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:22:18
		 *
		 * \param path �ļ�·����
		 */
		void setFilePath(const std::string & path);

		/*!
		 * \brief
		 * ��ȡ�ļ�·����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:23:37
		 *
		 * \return �ļ�·����
		 */
		const std::string * getFilePath() const;

		/*!
		 * \brief
		 * ��ȡ���ݿ����͡�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:25:11
		 *
		 * \return ���ݿ����͡�
		 */
		virtual DataBaseType databaseType();

		/*!
		 * \brief
		 * ��ȡ�ϴβ����Ĵ�����Ϣ��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:26:59
		 *
		 * \return ������Ϣ��
		 */
		virtual const std::string * errorMessage();

		/*!
		 * \brief
		 * �������ݿ⡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:27:28
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool connectDataBase();

		/*!
		 * \brief
		 * �Ͽ����ݿ����ӡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:35:27
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool disconnectDataBase();

		/*!
		 * \brief
		 * ��ȡ����״̬��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:45:14
		 *
		 * \return ����ת̨��
		 */
		virtual ConnectState connectState();

		/*!
		 * \brief
		 * �������ݿ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:49:34
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool beginTransaction();

		/*!
		 * \brief
		 * �ύ����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:52:02
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool commitTransaction();

		/*!
		 * \brief
		 * �ع�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 13:55:39
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool rollbackTransaction();

		/*!
		 * \brief
		 * ʵ��SQL��䣬�������ݣ�ʹ�ý���ע���ͷ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:11:02
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �������ݣ�ʧ�ܷ���NULL�����ص����ݼ�ʹ��YLR::YDataInterface::releaseDataTable�����ͷš�
		 */
		virtual const YDataTable * executeSqlReturnDt(const std::string & sql)  = 0;

		/*!
		 * \brief
		 * ִ��û�����ݷ��ص�sql��䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:13:18
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool executeSqlWithOutDt(const std::string & sql)  = 0;
	private:
		YDataInterface::DataBaseType _databaseType; /*!< ���ݿ����͡� */
		YDataInterface::ConnectState _connectState; /*!< �������͡� */

		std::string * _filePath; /*!< �ļ��洢·���� */

		sqlite3 * _db; /*!< ���ݿ�ָ�롣 */
		std::string * _errorText; /*!< ������Ϣ�� */
	};
}

#endif