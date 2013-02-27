#ifndef Y_ACCESS_DATABASE
#define Y_ACCESS_DATABASE

#include "YDataInterface.h"
#include "ado\MSAdo.h"

/*!
 * \brief
 * ������VC���ݿ����⡣
 */
namespace YLR
{
/*!
 * \brief
 * ���ݿ������⡣
 */
namespace YDataBase
{
	/*!
	 * \brief
	 * Access���ݿ�����ࡣ
	 * ���ߣ���˧ ����ʱ�䣺2013-2-27 14:28:28
	 */
	class YDATABASE_API YAccessDataBase : public YDataInterface
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 */
		YAccessDataBase();

		/*!
		 * \brief
		 * �������캯����
		 */
		YAccessDataBase(const YAccessDataBase & item);

		/*!
		 * \brief
		 * ����������
		 */
		~YAccessDataBase();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:14:54
		 *
		 * \item Դ��������
		 */
		YAccessDataBase & operator=(const YAccessDataBase & item);

		/*!
		 * \brief
		 * �����ļ�����·����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:18:28
		 *
		 * \param path �ļ�����·����
		 */
		void setFilePath(const std::string & path);

		/*!
		 * \brief
		 * ��ȡ�ļ�����·����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:22:12
		 *
		 * \return �ļ�����·����
		 */
		const std::string * getFilePath() const;

		/*!
		 * \brief
		 * �������롣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:24:53
		 *
		 * \param password ���롣
		 */
		void setPassword(const std::string & password);

		/*!
		 * \brief
		 * ��ȡ���롣
		 * ���ߣ���˧ ����ʱ�䣺����
		 *
		 * \return ���롣
		 */
		const std::string * getPassword() const;

		/*!
		 * \brief
		 * ��ȡ���ݿ����͡�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:37:29
		 *
		 * \return ���ݿ����͡�
		 */
		virtual DataBaseType databaseType();

		/*!
		 * \brief
		 * ��ȡ�ϴβ����Ĵ�����Ϣ��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:34:16
		 *
		 * \return ������Ϣ��
		 */
		virtual const std::string * errorMessage();

		/*!
		 * \brief
		 * �������ݿ⡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 14:38:42
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool connectDataBase();

		/*!
		 * \brief
		 * �Ͽ����ݿ����ӡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:05:54
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool disconnectDataBase();

		/*!
		 * \brief
		 * ��ȡ����״̬��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:07:46
		 *
		 * \return ����ת̨��
		 */
		virtual ConnectState connectState();

		/*!
		 * \brief
		 * �������ݿ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:08:40
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool beginTransaction();

		/*!
		 * \brief
		 * �ύ����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:09:49
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool commitTransaction();

		/*!
		 * \brief
		 * �ع�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:11:02
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool rollbackTransaction();

		/*!
		 * \brief
		 * ʵ��SQL��䣬�������ݣ�ʹ�ý���ע���ͷ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:11:38
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �������ݣ�ʧ�ܷ���NULL�����ص����ݼ�ʹ��YLR::YDataInterface::releaseDataTable�����ͷš�
		 */
		virtual const YDataTable * executeSqlReturnDt(const std::string & sql);

		/*!
		 * \brief
		 * ִ��û�����ݷ��ص�sql��䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-20 15:13:11
		 *
		 * \param sql Ҫִ�е�SQL��䡣
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool executeSqlWithOutDt(const std::string & sql);

	private:
		std::string * _filePath; /*!< �ļ�����·���� */ 
		std::string * _password; /*!< �ļ���½���롣 */

		DataBaseType _dataBaseType; /*!< ���ݿ����͡� */

		std::string * _errorText; /*!< ������Ϣ�� */

		_ConnectionPtr *_connection; /*!< ado���ݿ����Ӷ��� */
	};
}
}
#endif