// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YNETWORK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YNETWORK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YNETWORK_EXPORTS
#define YNETWORK_API __declspec(dllexport)
#else
#define YNETWORK_API __declspec(dllimport)
#endif

// �����Ǵ� YNetwork.dll ������
class YNETWORK_API CYNetwork {
public:
	CYNetwork(void);
	// TODO: �ڴ�������ķ�����
};

extern YNETWORK_API int nYNetwork;

YNETWORK_API int fnYNetwork(void);
