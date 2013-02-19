#ifndef Y_CONNECTION
#define Y_CONNECTION

#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#include "../../YNetwork/YNetwork.h"

#include "../YDataType/YByteType.h"

/*!
 * \brief
 * ������VC���ݿ����⡣
 */
namespace YLR
{

/*!
 * \brief
 * ���������⡣
 */
namespace YNetWork
{
	/*!
	 * \brief
	 * �������Ӵ����࣬������������״̬�����ݴ��䡣
	 * ���ݴ�����������ݰ���ʽΪ��
	 * ���ݰ��ֶ�˵��:     |״̬��|���ݰ��ܸ���|��ǰ���ݰ����|���ݰ������ݳ���|����|����|
	 * �����ֶγ���(�ֽ�): | 1    |   4       |     4       |     4         | x  | 1 |
	 * 
	 * ��ϸ˵����
	 * ״̬�֣���ʶ�����ݰ������ͣ�״̬������ΪStatusWord�еġ�
	 * ���ݰ��ܸ��������η��͵����ݱ��ֳɵ����ݰ��������޷������Ρ�
	 * ��ǰ���ݰ���ţ����η��͵����ݰ����ܸ����е���ţ��޷������Ρ�
	 * ���ݰ������ݳ��ȣ������ݰ��е����ݳ��ȣ��޷������Ρ�
	 * ���ݣ����ݰ��е����ݣ�����Ϊ���ݰ������ݳ���Լ���ĳ��ȡ�
	 * ������ʹ�ÿ��ַ���'\0'����Ϊ������ʶ��
	 *
	 * ���ߣ���˧ ����ʱ�䣺2013-2-17 14:43:41
	 */
	class YNETWORK_API YConnection
	{
	public:
		enum StatusWord
		{
			EndFlag = 0x00,        /*!< ���ݰ�����λ�� */

			Yes = 0x01,            /*!< ����ɹ��� */
			No = 0x02,             /*!< ����ʧ�ܡ� */
			Go = 0x03,             /*!< ������ */
			End = 0x04,            /*!< ������ */
			Error = 0x05,          /*!< ���� */

			Connect = 0x11,        /*!< �������ӡ� */
			Disconnect = 0x12,     /*!< ����Ͽ����ӡ� */

			SendData = 0x21,       /*!< ���������ݡ� */

			DataPackage = 0xFF     /*!< ���ݰ���������״̬�� */
		};

		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2013-2-17 14:45:27
		 */
		YConnection();

		/*!
		 * \brief
		 * �����׽��ֽ��ճ�ʱʱ�䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-2-18 13:07:40
		 *
		 * \param s Ҫ���õ��׽��֡�
		 * \param t ��ʱʱ�䣬��λ�����룩��
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		bool setRcvTimeOut(SOCKET s,const int &t);

		/*!
		 * \brief
		 * ��ȡ�׽��ֽ��ճ�ʱʱ�䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-2-18 13:16:52
		 *
		 * \param s Ҫ��ȡ���׽��֡�
		 *
		 * \return ��ʱʱ�䣬��λ�����룩��ʧ�ܷ���-1��
		 */
		int getRcvTimeOut(SOCKET s);

		/*!
		 * \brief
		 * ���÷��ͳ�ʱʱ�䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-2-18 14:33:37
		 *
		 * \param s Ҫ���õ��׽��֡�
		 * \param t ��ʱʱ�䣬��λ�����룩��
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		bool setSndTimeOut(SOCKET s,const int &t);

		/*!
		 * \brief
		 * ��ȡ�׽��ַ��ͳ�ʱʱ�䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-2-18 14:45:46
		 *
		 * \param s Ҫ��ȡ���׽��֡�
		 *
		 * \return ��ʱʱ�䣬��λ�����룩��ʧ�ܷ���-1��
		 */
		int getSndTimeOut(SOCKET s);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-2-18 14:56:57
		 *
		 * \param s ʹ�õ��׽��֡�
		 * \param data Ҫ���͵����ݡ�
		 * \param packageCount ÿһ�η��͵����ݳ��ȣ�������ݽϳ���Ҫ������ɸ������ͣ�ֻ��Ҫ����ÿ�����ĳ��ȼ��ɣ�����λ���ֽڡ�
		 * \param sendTimeOut ÿ�����ķ��ͳ�ʱʱ�䡣
		 * \param rcvTimeOut ÿ�����Ľ��ճ�ʱʱ�䡣
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		bool sendData(SOCKET s,const YDataType::YByteType &data,const int &packageCount,const int &sndTimeOut,const int &rcvTimeOut);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2013-2-19 11:26:06
		 *
		 * \param s ʹ�õ��׽��֡�
		 * \param data ���յ������ݡ�
		 * \param bufLength �������ݻ�������С��
		 * \param sendTimeOut ÿ�����ķ��ͳ�ʱʱ�䡣
		 * \param rcvTimeOut ÿ�����Ľ��ճ�ʱʱ�䡣
		 *
		 * \return �ɹ�����true�����򷵻�false��
		 */
		bool recaiveData(SOCKET s,YDataType::YByteType &data,const int &bufLength,const int &sndTimeOut,const int &rcvTimeOut);
	};
}
}

#endif