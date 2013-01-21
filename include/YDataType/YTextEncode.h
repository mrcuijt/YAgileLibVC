#ifndef Y_TEXT_ENCODE
#define Y_TEXT_ENCODE

#include <string>

#include "YDataTypeConfig.h"

namespace YLR
{
	/*!
	 * \brief
	 * ���뼯ת�������ࡣ
	 * ���ߣ���˧ ����ʱ�䣺2013-1-21 17:47:08
	 */
	class YBYTETYPE_API YTextEncode
	{
	public:
		/*!
		 * \brief
		 * �ͷ��ı��ռ䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 17:46:37
		 *
		 * \param text �ı�ָ�롣
		 */
		static void freeText(std::string * text);

		/*!
		 * \brief
		 * �ͷ��ı��ռ䡣
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 17:46:37
		 *
		 * \param text �ı�ָ�롣
		 */
		static void freeText(std::wstring * text);

		/*!
		 * \brief
		 * ��utf8ת����unicode��
		 * ���ߣ���˧ ����ʱ�䣺2013-1-21 17:48:32
		 *
		 * \param text Ҫת�����ı���
		 *
		 * \return ת������ı���������NULL������ʹ��freeText�����ͷš�
		 */
		static std::wstring * utf8ToUnicode(const std::string & text);
	};
}

#endif