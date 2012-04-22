#ifndef Y_DATA
#define Y_DATA

#include <string>

#include "YDataTypeConfig.h"
#include "YByteType.h"

namespace YLR
{
	/*!
	 * \brief
	 * �Զ���ͨ���������ͣ����ڳ��������������ݵı�����໥ת����
	 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:00:49
	 * �汾�ţ�v0.1.0
	 * ��Ҫ���ܣ�
	 * ���int��double��float��string���͵ı�����໥ת����
	 */
	class YBYTETYPE_API YData : public YByteType
	{
	public:

		/*!
		 * \brief
		 * �Զ��������������ࡣ
		 */
		enum DatyType
		{
			YNull,       /*!< NULL���� */
			YInt,         /*!< int���� */
			YDouble,      /*!< double���� */
			YFloat,       /*!< float���� */
			YString       /*!< string���� */
		};

		/*!
		 * \brief
		 * Ĭ�Ϲ��캯�������ݳ�ʼ����NULL��
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:03:24
		 */
		YData();

		/*!
		 * \brief
		 * ʹ��int���͵����ݳ�ʼ���Ĺ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:11:12
		 *
		 * \param d ��ʼ�������ݡ�
		 */
		YData(const int &d);

 		/*!
		 * \brief
		 * ʹ��double���͵����ݳ�ʼ���Ĺ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:34:16
		 *
		 * \param d ��ʼ�������ݡ�
		 */
		YData(const double &d);

		/*!
		 * \brief
		 * ʹ��float���͵����ݳ�ʼ���Ĺ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:38:16
		 *
		 * \param d ��ʼ�������ݡ�
		 */
		YData(const float &d);

		/*!
		 * \brief
		 * ʹ��string���͵����ݳ�ʼ���Ĺ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:45:46
		 *
		 * \param d ��ʼ�������ݡ�
		 */
		YData(const std::string &d);

		/*!
		 * \brief
		 * ��ȡ�������͡�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 17:23:45
		 *
		 * \return �������͡�
		 */
		YData::DatyType getDataType() const;

		/*!
		 * \brief
		 * ���������ó�NULL��
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 15:59:51
		 */
		void setNull();

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 16:41:16
		 *
		 * \param d ����
		 */
		void setFrom(const int &d);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 16:41:29
		 *
		 * \param d ����
		 */
		void setFrom(const double &d);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 16:41:29
		 *
		 * \param d ����
		 */
		void setFrom(const float &d);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 16:41:29
		 *
		 * \param d ����
		 */
		void setFrom(const std::string &d);

		/*!
		 * \brief
		 * ת����int���ͣ�ʹ��ǰ��getDataType����������͡�
		 * ���ߣ���˧ ����ʱ�䣺2012-4-22 16:50:30
		 *
		 * \return ת��������ݡ�
		 */
		int toInt() const;

	protected:
		YData::DatyType _type;
	};
};

#endif