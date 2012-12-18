#ifndef Y_DATA_COLUMNS
#define Y_DATA_COLUMNS

#include "../../YDataBase/DLL_Config.h"
#include "YColumn.h"

namespace YLR 
{
/** 
 * \brief
 * ���ݱ��ֶνӿڶ��塣
 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:11:19
 */
class YDATABASE_API YDataColumns {

 public:


    /*! 
     * \brief
	 * �������к�������һ�С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:11:55
	 *
	 * \param column ���ӵ��С�
     */
    virtual void addColumn(const YColumn & column) = 0;


    /*!
     * \brief
	 * ��ָ��λ�ò��������С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:16:13
	 *
	 * \param index ����λ�ã���0��ʼ��
	 * \param column ������С�
     */
    virtual void insertColumn(const int & index, const YColumn & column) = 0;


    /*!
     * \brief
	 * �Ƴ�ָ��λ�õ������С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:17:16
	 *
	 * \param index Ҫ�Ƴ���������λ�ã���0��ʼ��
     */
    virtual void removeColumn(const int & index) = 0;

	/*!
	 * \brief
	 * ��ȡָ��λ�õ������У����ָ��λ�ò����ڷ���NULL��
	 * ���ߣ���˧ ����ʱ�䣺2012-12-18 12:41:18
	 *
	 * \param index ��������������0��ʼ��
	 *
	 * \return ����������ָ�롣
	 */
	virtual const YColumn * getColumn(const int & index) const = 0;

	/*!
	 * \brief
	 * ����ָ��λ�õ������У����ָ��λ�ò����ڲ����κβ�����
	 * ���ߣ���˧ ����ʱ�䣺2012-12-18 12:45:33
	 *
	 * \param index ����λ�ã���0��ʼ��
	 * \param column �����С�
	 */
	virtual void setColumn(const int & index, const YColumn & column) = 0;

	/*!
	 * \brief
	 * ��ȡ������������
	 * ���ߣ���˧ ����ʱ�䣺2012-12-18 17:28:10
	 *
	 * \return ��������
	 */
	virtual int getColumnCount() const  = 0;
};

}

#endif