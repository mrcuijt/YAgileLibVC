// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� YSERIALPORT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// YSERIALPORT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef YSERIALPORT_EXPORTS
#define YSERIALPORT_API __declspec(dllexport)
#else
#define YSERIALPORT_API __declspec(dllimport)
#endif

// �����Ǵ� YSerialPort.dll ������
class YSERIALPORT_API CYSerialPortPro {
public:
	CYSerialPortPro(void);
	// TODO: �ڴ�������ķ�����
};

extern YSERIALPORT_API int nYSerialPort;

YSERIALPORT_API int fnYSerialPort(void);
