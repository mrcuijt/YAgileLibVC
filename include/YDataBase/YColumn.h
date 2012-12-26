#ifndef Y_COLUMN
#define Y_COLUMN

#include "../../YDataBase/DLL_Config.h"
#include "../YDataType/YData.h"

#include <string>

namespace YLR
{
	/*!
	 * \brief
	 * �����ֶΡ�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-5 21:49:49
	 */
	class YDATABASE_API YColumn 
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯������ʼ�����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 21:53:34
		 */
		YColumn();

		/*!
		 * \brief
		 * �������ݳ�ʼ���Ĺ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:02:19
		 *
		 * \param physicaName ��������
		 * \param logicalName �߼�����
		 * \param dataType ��������
		 */
		YColumn(const std::string & physicaName, const std::string & logicalName, const YData::DataType & dataType);

		/*!
		 * \brief
		 * �������캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:06:05
		 *
		 * \param item Ҫ�����Ķ���
		 */
		YColumn(const YColumn & item);
		
		/*!
		 * \brief
		 * �����������ͷŶ���������Դ��
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:14:54
		 */
		~YColumn();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:14:54
		 *
		 * \param item ԭ���ݶ���
		 * 
		 * \return Ŀ�����á�
		 */
		YColumn & operator=(const YColumn & item);

		/*!
		 * \brief
		 * �����ֶ��������ơ�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:14:54
		 *
		 * \param physicaName ��������
		 */
		void setPhysicaName(const std::string & physicaName);

		/*!
		 * \brief
		 * ��ȡ�ֶ��������ơ�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:17:31
		 *
		 * \return �ֶ���������ָ��constָ�롣
		 */
		const std::string * getPhysicaName() const;

		/*!
		 * \brief
		 * �����ֶ��߼����ơ�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:36:20
		 *
		 * \param logicalName �ֶ��߼�����
		 */
		void setLogicalName(const std::string & logicalName);

		/*!
		 * \brief
		 * ��ȡ�ֶ��߼����ơ�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:38:25
		 *
		 * \return ����߼�����constָ�롣
		 */
		const std::string * getLogicalName() const;	

		/*!
		 * \brief
		 * �����������͡�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:46:12
		 *
		 * \param dataType �������͡�
		 */
		void setDataType(const YData::DataType & dataType);

		/*!
		 * \brief
		 * ��ȡ�ֶ��������͡�
		 * ���ߣ���˧ ����ʱ�䣺2012-11-5 22:48:28
		 *
		 * \return �ֶ��������͡�
		 */
		const YData::DataType getDataType() const;

	protected:
		std::string * _physicaName; /*!<�ֶ��������ơ� */
	
		std::string * _logicalName; /*!<�ֶ��߼����ơ� */
    
		YData::DataType _dataType; /*!<�ֶ��������͡� */
	};
}
#endif 