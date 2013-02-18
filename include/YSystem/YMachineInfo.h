#ifndef Y_MACHINE_INFO
#define Y_MACHINE_INFO

#include <string>

#include "../../YSystem/YSystem.h"

namespace YLR
{
/*!
 * \brief
 * ϵͳ��Ϣ��⡣
 */
namespace YSystem
{
	class YSYSTEM_API YMachineInfo
	{
	public:
		/*!
		 * \brief
		 * ��ȡCPUΨһ��ʶ��
		 * ���ߣ���˧ ����ʱ�䣺2013-2-9 21:30:43
		 *
		 * \return CPUΨһ��ʶ��ʧ�ܷ���NULL��ʹ�ú���freeText�����ͷš�
		 */
		static std::string * getCpuID();

		/*!
		 * \brief
		 * �ͷ��ַ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-2-9 21:31:35
		 *
		 * \param s Ҫ�ͷŵ��ַ�����
		 */
		static void freeText(std::string * s);
	};
}
}

#endif