// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YDATABASE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YDATABASE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YDATABASE_EXPORTS
#define YDATABASE_API __declspec(dllexport)
#else
#define YDATABASE_API __declspec(dllimport)
#endif

// �����Ǵ� YDataBase.dll ������
class YDATABASE_API CYDataBase {
public:
	CYDataBase(void);
	// TODO: �ڴ�������ķ�����
};

extern YDATABASE_API int nYDataBase;

YDATABASE_API int fnYDataBase(void);
