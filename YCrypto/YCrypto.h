// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YCRYPTO_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YCRYPTO_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YCRYPTO_EXPORTS
#define YCRYPTO_API __declspec(dllexport)
#else
#define YCRYPTO_API __declspec(dllimport)
#endif

// �����Ǵ� YCrypto.dll ������
class YCRYPTO_API CYCrypto {
public:
	CYCrypto(void);
	// TODO: �ڴ�������ķ�����
};

extern YCRYPTO_API int nYCrypto;

YCRYPTO_API int fnYCrypto(void);
