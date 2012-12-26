#ifndef Y_DATA_ROW
#define Y_DATA_ROW

#include <vector>

#include "../../YDataBase/DLL_Config.h"
#include "YDataColumns.h"

namespace YLR
{
	/*!
	 * \brief
	 * ���������ͷ�װ��
	 * ���ߣ���˧ ����ʱ�䣺2012-12-10 19:58:12
	 */
	class YDATABASE_API YDataRow : public YDataColumns 
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-10 20:05:21
		 */
		YDataRow();

		/*!
		 * \brief
		 * �������캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-12 21:26:09
		 */
		YDataRow(const YDataRow & item);

		/*!
		 * \brief
		 * ����������
		 */
		~YDataRow();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-12 21:37:50
		 */
		YDataRow & operator=(const YDataRow & item);

		/*!
		 * \brief
		 * �������к�������һ�С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-12 21:42:22
		 *
		 * \param column ���ӵ��С�
		 */
		virtual void addColumn(const YColumn & column);

		/** 
		 * \brief
		 * ��ָ��λ�ò��������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-12 22:13:23
		 *
		 * \param index ����λ�ã���0��ʼ��
		 * \param column ������С�
		 */
		virtual void insertColumn(const int & index, const YColumn & column);

		/*!
		 * \brief
		 * �Ƴ�ָ��λ�õ������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-12 22:13:27
		 *
		 * \param index Ҫ�Ƴ���������λ�ã���0��ʼ��
		 */
		virtual void removeColumn(const int & index);

		/*!
		 * \brief
		 * ��ȡָ��λ�õ������У����ָ��λ�ò����ڷ���NULL��
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 12:41:18
		 *
		 * \param index ��������������0��ʼ��
		 *
		 * \return ����������ָ�롣
		 */
		virtual const YColumn * getColumn(const int & index) const;

		/*!
		 * \brief
		 * ����ָ��λ�õ������У����ָ��λ�ò����ڲ����κβ�����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 12:45:33
		 *
		 * \param index ����λ�ã���0��ʼ��
		 * \param column �����С�
		 */
		virtual void setColumn(const int & index, const YColumn & column);

		/*!
		 * \brief
		 * ��ȡ������������
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:28:10
		 *
		 * \return ��������
		 */
		virtual int getColumnCount() const;

		/*!
		 * \brief
		 * ��ȡ���ݡ�
		 * ���ߣ���˧ �����ļ���2012-12-12 22:22:50
		 *
		 * \param index ����ֵ��
		 *
		 * \return ����ָ�룬ʧ�ܷ���NULL��
		 */
		const YData * getData(const int & index) const;

		/*!
		 * \brief
		 * ��ȡ���ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 12:54:51
		 *
		 * \param physicaName �ֶ��߼����ơ�
		 *
		 * \return ����ָ�룬ʧ�ܷ���NULL��
		 */
		const YData * getData(const std::string & physicaName) const;

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 13:04:31
		 * 
		 * \param index ����λ�ã���0��ʼ��
		 * \param data ���ݡ�
		 */
		void setData(const int & index, const YData & data);

		/*!
		 * \brief
		 * �������ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 13:10:26
		 * 
		 * \param physicaName �߼����ơ�
		 * \param data ���ݡ�
		 */
		void setData(const std::string & physicaName, const YData & data);
	protected:
		std::vector<YColumn> * _columns; /*!< ���ֶ��б� */
    
		std::vector<YData> * _datas; /*!< �����б� */
	};
};

#endif