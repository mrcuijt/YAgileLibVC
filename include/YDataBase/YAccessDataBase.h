#ifndef Y_ACCESS_DATABASE
#define Y_ACCESS_DATABASE

#include "YDataInterface.h"
#include "ado\MSAdo.h"

namespace YLR
{
	class YDATABASE_API YAccessDataBase : public YDataInterface
	{
	public:
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 */
		YAccessDataBase();

		/*!
		 * \brief
		 * �������캯����
		 */
		YAccessDataBase(const YAccessDataBase & item);

		/*!
		 * \brief
		 * 
		 */
		void setFilePath(const std::string & path);

	private:
		std::string * _filePath; /*!< �ļ�����·���� */ 
		std::string * _password; /*!< �ļ���½���롣 */
	};
}

#endif