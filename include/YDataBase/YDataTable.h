#ifndef Y_DATA_TABLE
#define Y_DATA_TABLE

#include <vector>

#include "../../YDataBase/DLL_Config.h"
#include "YDataRow.h"

namespace YLR
{
	/*!
	 * \brief
	 * ���ݱ����ͷ�װ�� 
	 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:12:12
	 */
	class YDATABASE_API YDataTable : public YDataColumns 
	{
	public:
		/*!
		 * \brief
		 * ���캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:15:27
		 */
		YDataTable();

		/*!
		 * \brief
		 * �������캯����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:19:00
		 */
		YDataTable(const YDataTable & item);

		/*!
		 * \brief
		 * ����������
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:21:10
		 */
		~YDataTable();

		/*!
		 * \brief
		 * ��ֵ���������ء�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:23:26
		 */
		YDataTable & operator=(const YDataTable & item);

		/*!
		 * \brief
		 * �������к�������һ�С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:25:13
		 *
		 * \param column ���ӵ��С�
		 */
		virtual void addColumn(const YColumn & column);

		/** 
		 * \brief
		 * ��ָ��λ�ò��������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:25:17
		 *
		 * \param index ����λ�ã���0��ʼ��
		 * \param column ������С�
		 */
		virtual void insertColumn(const int & index, const YColumn & column);

		/*!
		 * \brief
		 * �Ƴ�ָ��λ�õ������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:25:22
		 *
		 * \param index Ҫ�Ƴ���������λ�ã���0��ʼ��
		 */
		virtual void removeColumn(const int & index);

		/*!
		 * \brief
		 * ��ȡָ��λ�õ������У����ָ��λ�ò����ڷ���NULL��
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:25:26
		 *
		 * \param index ��������������0��ʼ��
		 *
		 * \return ����������ָ�롣
		 */
		virtual const YColumn * getColumn(const int & index) const;

		/*!
		 * \brief
		 * ����ָ��λ�õ������У����ָ��λ�ò����ڲ����κβ�����
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:25:29
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
		 * �ڱ�ĩβ���������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:38:26
		 *
		 * \param row �����С�
		 */
		void addRow(const YDataRow & row);

		/*!
		 * \brief
		 * ���������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:43:28
		 *
		 * \param index ����λ�á�
		 */
		void insertRow(const int & index, const YDataRow & row);

		/*!
		 * \brief
		 * �Ƴ�ָ���������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:51:22
		 *
		 * \param index ����λ�á�
		 */
		void removeRow(const int & index);

		/*!
		 * \brief
		 * ��ȡָ��λ�õ������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:54:22
		 *
		 * \param index ����λ�á�
		 *
		 * \return ������ָ�룬������NULL��
		 */
		const YDataRow * getRow(const int & index) const;

		/*!
		 * \brief
		 * ���������С�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:57:20
		 *
		 * \param index ����λ�á�
		 * \param row �����С�
		 */
		void setRow(const int & index, const YDataRow & row);

		/*!
		 * \brief
		 * ��ȡ������������
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:31:18
		 *
		 * \return ��������
		 */
		int getRowCount() const;

		/*!
		 * \brief
		 * ��ȡָ��λ�õ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 16:59:39
		 *
		 * \param rowIndex ������ֵ��
		 * \param columnIndex ������ֵ��
		 * 
		 * \return ����ָ�롣
		 */
		const YData * getData(const int & rowIndex, const int & columnIndex) const;

		/*!
		 * \brief
		 * ��ȡָ��λ�õ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:07:36
		 *
		 * \param rowIndex ������ֵ��
		 * \param physicaName ���߼����ơ�
		 * 
		 * \return ����ָ�롣
		 */
		const YData * getData(const int & rowIndex, const std::string & physicaName) const;

		/*!
		 * \brief
		 * ��ȡָ��λ�õ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:07:36
		 *
		 * \param rowIndex ������ֵ��
		 * \param columnIndex ������ֵ��
		 * \param data ���ݡ�
		 */
		void setData(const int & rowIndex, const int & columnIndex, const YData & data);

		/*!
		 * \brief
		 * ��ȡָ��λ�õ����ݡ�
		 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:13:52
		 *
		 * \param rowIndex ������ֵ��
		 * \param physicaName ���߼����ơ�
		 * \param data ���ݡ�
		 */
		void setData(const int & rowIndex, const std::string & physicaName, const YData & data);
	protected:
		std::vector<YColumn> * _columns; /*!< �����С� */
		std::vector<YDataRow> * _rows; /*!< �����С� */
	};
}

#endif