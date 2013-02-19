#ifndef Y_BYTE_TYPE
#define Y_BYTE_TYPE
// �����Ǵ� YByteType.dll ������



#ifndef YBYTE
#define YBYTE unsigned char /*!< �Զ���������������� */
#endif

#include "YDataTypeConfig.h"

#include <stdio.h>
//#include <vector>
//#include <list>

namespace YLR
{
/*!
 * \brief
 * ��װһЩ���õ��������ͺ��������͵Ĳ�����
 */
namespace YDataType
{
/*!
 * \brief
 * �����Ʋ����࣬ʹ��Win32��Ŀ����DLL���ڹ��������á����������д����ʹ�ñ�׼C++����������Ŀ��ֲ��
 * ���ߣ���˧ ����ʱ�䣺2011-11-22 10:56
 */
class YBYTETYPE_API YByteType 
{
public:

	/*!
	 * \brief
	 * ���캯�������Ը���ָ�������ݳ�ʼ����
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 11:00
	 *
	 * \param count ���ݿռ��ʼ��С��Ĭ��ֵ��0����ʽ�ݲ����䡣
	 * \param initData ���ݿռ��ʼ����������Ĭ��ֵ��NULL����ʽ�޳�ʼ�����ݡ�����г�ʼ������һ��Ҫ��֤���ݵĸ�����count��ȡ�
	 */
	YByteType(const unsigned int &count = 0, const YBYTE * initData = NULL);

	/*!
	 * \brief �������캯��
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 11:10
	 *
	 * \param item Ҫ���Ƶ����ݶ���
	 */
	YByteType(const YByteType &item);

	/*!
	 * \brief
	 * �������������������ݿռ��������ͷš�
	 * �汾��v0.1.0 ���ߣ���˧ ����ʱ�䣺2011-11-22 11:20
	 */	 
	~YByteType();

	/*!
	 * \brief
	 * �������ݿռ䣬ԭ���ݴ洢�ռ��е�����ҲҪ�����´���
	 * �¿ռ�С�ڵ���ԭ�ռ�ʱ�����¿ռ俪ʼλ���𣬸����¿ռ�Ĵ�С����ԭ�����ݰ�˳�򱣴浽�¿ռ��У��������¿ռ��С֮�������������
	 * �¿ռ����ԭ�ռ�ʱ�����¿ռ���ʼλ�ÿ�ʼ����ԭ�����ݰ�˳�򱣴浽�¿ռ��С�
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 11:30
	 *
	 * \param count ���ݿռ��С��Ĭ��ֵ��0����ʽ������ݡ�
	 *
	 * \return ������ô�С�ɹ��򷵻�true�����򷵻�false��
	 */
	bool setSize(const unsigned int &count = 0);

	/*!
	 * \brief
	 * ��ȡ���ݿռ��С��
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 11:48
	 *
	 * \return ���ݿռ��С��
	 */
	unsigned int getSize() const;

	/*!
	 * \brief
	 * ���õ������ݣ����ָ����λ�ó�����Χ����������������ý����󷵻����ݸ�����
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 13:35
	 *
	 * \param data Ҫ���õ�����
	 * \param location Ҫ���õ�����λ�ã�Ĭ����0��
	 *
	 * \return ���õ����ݸ���,����Ӧ�÷���1����������ʧ�ܡ�
	 */
	unsigned int setData(const YBYTE &data, const unsigned int &location = 0);

	/*!
	 * \brief
	 * �����������ݣ����������Χ�����������������ý����������õ����ݸ�����
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 13:40
	 *
	 * \param data Ҫ���õ����������׵�ַ
	 * \param count Ҫ���õ����ݸ�����Ĭ��ֵ��0����ʱʹ��'\0'��־������
	 * \param location ���ݿռ俪ʼλ��
	 *
	 * \return ���õ����ݸ���
	 */
	unsigned int setData(const YBYTE * data, const unsigned int &count, const unsigned int &location = 0);

	/*!
	 * \brief
	 * ��ȡ���ݡ�
	 * �汾��v0.1.0 ���ߣ���˧ ����ʱ�䣺2011-11-22 13:54
	 *
	 * \param data Ҫ��ȡ�����ݷ���ֵ��
	 * \param location ���ݿռ��λ�ã����ָ��λ�ó�����Χ�򲻽����κβ�����
	 *
	 * \return ���ػ�ȡ�����ݸ���������Ӧ�÷���1��
	 */
	unsigned int getData(YBYTE &data, const unsigned int &location = 0) const;

	/*!
	 * \brief
	 * ������ȡ���ݣ������ȡ�ĸ���������Χ�������������֡�
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 13:59
	 *
	 * \param data �洢���������׵�ַ
	 * \param count ��ȡ���ݸ���������������ݿռ䷶Χ����������������
	 * \param location ���ݿռ俪ʼλ�ã�Ĭ����0
	 *
	 * \return ���ػ�ȡ�����ݸ�����
	 */
	unsigned int getData(YBYTE * data, const unsigned int &count, const unsigned int &location = 0) const;

	/*!
	 * \brief
	 * ��ֵ����������
	 * ���ߣ���˧ ����ʱ�䣺2011-11-22 14:10
	 *
	 * \param item Ҫ���Ƶ�ԭ������
	 */
	YByteType & operator=(const YByteType &item);

protected:
	YBYTE * _data; /*!< ���ݿռ��ַ����ʼֵ��NULL����ʽ��δ���䡣 */
	unsigned int _size; /*!< ���ݴ洢�ռ��С����ʼֵ��0����ʽδ����ռ䡣 */
};


//template class YBYTETYPE_API std::allocator<YByteType>;
//
//template class YBYTETYPE_API std::vector<YByteType,std::allocator<YByteType>>;
//
//template class YBYTETYPE_API std::allocator<std::_List_nod<YByteType,std::allocator<YByteType> >::_Node>;
//template class YBYTETYPE_API std::list<YByteType,std::allocator<YByteType>>;

}
}
#endif