// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YDATATYPE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YDATATYPE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YDATATYPE_EXPORTS
#define YDATATYPE_API __declspec(dllexport)
#else
#define YDATATYPE_API __declspec(dllimport)
#endif

// �����Ǵ� YDataType.dll ������
class YDATATYPE_API CYDataType {
public:
	CYDataType(void);
	// TODO: �ڴ�������ķ�����
};

extern YDATATYPE_API int nYDataType;

YDATATYPE_API int fnYDataType(void);
