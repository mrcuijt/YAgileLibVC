#ifndef Y_DATA_INTERFACE
#define Y_DATA_INTERFACE

#include <string>

#include "../../YDataBase/DLL_Config.h"
#include "YDataTable.h"

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
	 * ���ݿ����ӽӿڣ������������ݿ����ӵı�׼������
	 * ���ߣ���˧ ����ʱ�䣺2013-1-7 15:58:09
	 */
	class YDATABASE_API YDataInterface
	{
	public:

		/*!
		 * \brief
		 * ���ݿ�����״̬ö��ֵ��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:02:17��
		 */
		enum ConnectState
		{
			Connected,          /*!< �Ѿ����ӡ� */
			Disconnected        /*!< ���ӶϿ��� */
		};

		/*!
		 * \brief
		 * ���ݿ����͡�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:04:05
		 */
		enum DataBaseType
		{
			MSSQL,            /*!< ΢��SqlServer���ݿ⡣ */
			Access,           /*!< ΢��Access���ݿ⡣ */
			SQLite            /*!< SQLite���ݿ⡣ */
		};

		/*!
		 * \brief
		 * ��ȡ���ݿ����͡�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 15:58:46
		 *
		 * \return ���ݿ����͡�
		 */
		virtual DataBaseType databaseType()  = 0;

		/*!
		 * \brief
		 * ��ȡ�ϴβ����Ĵ�����Ϣ��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 15:59:23
		 *
		 * \return ������Ϣ��
		 */
		virtual const std::string * errorMessage()  = 0;

		/*!
		 * \brief
		 * �������ݿ⡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:00:35
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool connectDataBase()  = 0;

		/*!
		 * \brief
		 * �Ͽ����ݿ����ӡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:06:04
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool disconnectDataBase()  = 0;

		/*!
		 * \brief
		 * ��ȡ����״̬��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:06:51
		 *
		 * \return ����ת̨��
		 */
		virtual ConnectState connectState()  = 0;

		/*!
		 * \brief
		 * �������ݿ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:07:56
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool beginTransaction()  = 0;

		/*!
		 * \brief
		 * �ύ����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:08:59
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool commitTransaction()  = 0;

		/*!
		 * \brief
		 * �ع�����
		 * ���ߣ���˧ ����ʱ�䣺2013-1-7 16:09:40
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		virtual bool rollbackTransaction()  = 0;

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

		/*!
		 * \brief
		 * �ͷ����ݼ���
		 * ���ߣ���˧ ����ʱ�䣺2013-1-16 17:40:35
		 *
		 * \param t Ҫ�ͷŵ����ݼ���
		 */
		static void releaseDataTable(const YDataTable *t)
		{
			delete t;
		}
	};
}
}
#endif