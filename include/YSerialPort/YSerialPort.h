#ifndef V_SERIAL_PORT
#define V_SERIAL_PORT

#ifdef YSERIALPORT_EXPORTS
#define YSERIALPORTCE_API __declspec(dllexport)
#else
#define YSERIALPORTCE_API __declspec(dllimport)
#endif

#include <windows.h>

namespace YLR
{


	/*!
	 * \brief 
	 * ����ͨ���࣬Ĭ�ϵĴ��ڲ���Ϊ��
	 * ���ںţ�COM1
	 * �����ʣ�9600
	 * У��λ��NONE
	 * ����λ��8
	 * ֹͣλ��1
	 *
	 * ����ʱ�䣺2011-06-08 9:00:00 �����ˣ���˧
	 * �汾�ţ�V0.1.0
	 *
	 * ��ԭ����MFC�����޸ĳ�Win32��̬�⡣
	 * �汾�ţ�v0.2.0 ���ߣ���˧ ����ʱ�䣺2012-1-12 16:45:44
	*/
	class YSERIALPORTCE_API YSerialPort
	{
	public:
		/*!
		\brief Ĭ�Ϲ��캯��
		*/
		YSerialPort(void);
		~YSerialPort(void);

		/*!
		\brief У��λ����
		*/
		enum Parity
		{
			NoParity = NOPARITY,
			ODDParity = ODDPARITY,
			EvenParity = EVENPARITY,
	 		MarkParity = MARKPARITY,
			SpaceParity = SPACEPARITY
		};

		/*!
		\brief ֹͣλ����
		*/
		enum StopBits
		{
			OneStopBit = ONESTOPBIT,
			One5StopBits = ONE5STOPBITS,
			TwoStopBits = TWOSTOPBITS
		};

		int serialNum; /*!< ���ں� */

		int baudRate; /*!< ������ */

		int byteSize; /*!< ����λ */

		Parity parity; /*!< У��λ */

		StopBits stopBits; /*!< ֹͣλ */

	private:
		HANDLE serialPort; /*!< ���ھ�� */
	public:
		/*!
		\brief �򿪴���

		\return �ɹ�����true�����򷵻�false
		\sa bool closeSerialPort(void)
		*/
		bool openSerialPort(void);

		/*!
		\brief �رմ���

		\return �ɹ�����true�����򷵻�false
		\sa bool openSerialPort(void)
		*/
		bool closeSerialPort(void);
		
		/*!
		\brief ��������

		\param data �������ݻ�������ַ
		\param count ���͵�����

		\return �ɹ����ط��͵��ֽ���������-1��ʽ����δ�򿪣�����-2��ʽ����ʧ�ܣ�
				-3��ʽ��շ��ͻ�����ʧ�ܣ�-4��ʽ��ս��ջ�����ʧ��
		\sa int receiveDate(unsigned char * data, const int & count)
		*/
		int sendData(const unsigned char * data, const int & count);
		
		/*!
		\brief ��������

		\param data �������ݻ�������ַ
		\param count ��������

		\return �ɹ����ؽ��յ��ֽ���������-1��ʽ����δ�򿪣�����-2��ʽ����ʧ��
		\sa int sendData(const unsigned char * data, const int & count);
		*/
		int receiveDate(unsigned char * data, const int & count);
	};
};
#endif