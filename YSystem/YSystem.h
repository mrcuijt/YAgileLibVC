// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YSYSTEM_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YSYSTEM_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YSYSTEM_EXPORTS
#define YSYSTEM_API __declspec(dllexport)
#else
#define YSYSTEM_API __declspec(dllimport)
#endif

// �����Ǵ� YSystem.dll ������
class YSYSTEM_API CYSystem {
public:
	CYSystem(void);
	// TODO: �ڴ�������ķ�����
};

extern YSYSTEM_API int nYSystem;

YSYSTEM_API int fnYSystem(void);
