// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YJSONCPP_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YJSONCPP_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YJSONCPP_EXPORTS
#define YJSONCPP_API __declspec(dllexport)
#else
#define YJSONCPP_API __declspec(dllimport)
#endif

// �����Ǵ� YJsonCpp.dll ������
class YJSONCPP_API CYJsonCpp {
public:
	CYJsonCpp(void);
	// TODO: �ڴ�������ķ�����
};

extern YJSONCPP_API int nYJsonCpp;

YJSONCPP_API int fnYJsonCpp(void);
