#ifndef Y_DATA_COLUMNS
#define Y_DATA_COLUMNS

#include "../include/YDataBase/YColumn.h"

namespace YLR 
{
/** 
 * \brief
 * ���ݱ��ֶνӿڶ��塣
 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:11:19
 */
class YDataColumns {

 public:


    /** 
     * \brief
	 * �������к�������һ�С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:11:55
	 *
	 * \param column ���ӵ��С�
     */
    virtual void addColumn(const YColumn & column)  = 0;


    /** 
     * \brief
	 * ��ָ��λ�ò��������С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:16:13
	 *
	 * \param index ����λ�ã���0��ʼ��
	 * \param column ������С�
     */
    virtual void insertColumn(const int & index, const YColumn & column)  = 0;


    /** 
     * \brief
	 * �Ƴ�ָ��λ�õ������С�
	 * ���ߣ���˧ ����ʱ�䣺2012-11-26 21:17:16
	 *
	 * \param index Ҫ�Ƴ���������λ�ã���0��ʼ��
     */
    virtual void removeColumn(const int & index)  = 0;
};

}

#endif