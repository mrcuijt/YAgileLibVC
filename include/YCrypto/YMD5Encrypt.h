#ifndef MD5_ENCRYPT
#define MD5_ENCRYPT

#include <string>
#include <fstream>
#include "../../YCrypto/YCrypto.h"

/* Type define */  
typedef unsigned char byte;  
typedef unsigned int uint32;

/*!
 * \brief
 * ������VC���ݿ����⡣
 */
namespace YLR
{
/*!
 * \brief
 * ���ܽ�����⡣
 */
namespace YCrypto
{
	/*!
	 * \brief
	 * MD5�����㷨�����ࡣ
	 * ���ߣ���˧ ����ʱ�䣺2013-2-6 20:58:21
	 */
	class YCRYPTO_API YMD5Encrypt
	{
	public: 
		/*!
		 * \brief
		 * Ĭ�Ϲ��캯����
		 */
		YMD5Encrypt();  
		 
		/*!
		 * \brief
		 * ��ȡ�����ַ�����
		 * ���ߣ���˧ ����ʱ�䣺2013-2-6 20:59:19
		 *
		 * \param s Ҫ���ܵ��ַ�����
		 *
		 * \return ���ܺ���ַ�����ʹ��freeText�����ͷ��ڴ棩��
		 */
		std::string * getMD5(const std::string &s);

		/*!
		 * \brief
		 * �ͷ��ڴ档
		 * ���ߣ���˧ ����ʱ�䣺2013-2-6 21:00:42
		 *
		 * \param s Ҫ�ͷŵ��ַ���ָ�롣
		 */
		static void freeText(std::string *s);
	private:  
		void update(const void *input, size_t length);  
		std::string * toString(); 
		const byte* digest();
		void reset();
		void update(const byte *input, size_t length);  
		void final();  
		void transform(const byte block[64]);  
		void encode(const uint32 *input, byte *output, size_t length);  
		void decode(const byte *input, uint32 *output, size_t length);  
		std::string * bytesToHexString(const byte *input, size_t length); 
	private:  
		uint32 _state[4];   /* state (ABCD) */  
		uint32 _count[2];   /* number of bits, modulo 2^64 (low-order word first) */  
		byte _buffer[64];   /* input buffer */  
		byte _digest[16];   /* message digest */  
		bool _finished;     /* calculate finished ? */  
  
		static const byte PADDING[64];  /* padding for calculate */  
		static const char HEX[16];  
	};
}
}

#endif