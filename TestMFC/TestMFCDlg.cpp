
// TestMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include "afxdialogex.h"

#include "../include/JsonCpp/json.h"
#include "../include/YDataType/YData.h"
#include "../include/YDataBase/YColumn.h"

#include "../include/YSerialPort/YSerialPort.h"

#include "../include/YDataBase/YSqlServerDataBase.h"
#include "../include/YDataBase/YSQLiteDataBase.h"
#include "../include/YDataBase/YAccessDataBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCDlg �Ի���




CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTestMFCDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestMFCDlg ��Ϣ�������

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	if(!AfxOleInit())//����ǳ�ʼ��COM��
	{
		AfxMessageBox(_T("OLE��ʼ������!"));
		return FALSE;
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMFCDlg::OnBnClickedOk()
{
	
	YLR::YSQLiteDataBase d1;
	d1.setFilePath("D:/SQLiteDB.db");

	if(d1.connectDataBase())
	{
		AfxMessageBox(_T("OK"));
		const YLR::YDataTable *table = d1.executeSqlReturnDt("SELECT * FROM tb_test");
		if(table != NULL)
		{
			for(int i = 0;i < table->getRowCount();i++)
			{
				CString str = _T("");;
				if(table->getData(i,0)->isNull())
				{
					str += "NULL";
				}
				else
				{
					CString ss;
					ss.Format(_T("%d"),table->getData(i,0)->toInt());
					str += ss;
				}

				if(table->getData(i,1)->isNull())
				{
					str += ",NULL";
				}
				else
				{
					YLR::YData data = YLR::YData(*table->getData(i,1));
					
					str += _T(",") + CString(data.toString()->c_str());
				}

				if(table->getData(i,2)->isNull())
				{
					str += ",NULL";
				}
				else
				{
					YLR::YData data = YLR::YData(*table->getData(i,2));
					
					str += _T(",") + CString(data.toString()->c_str());
				}

				if(table->getData(i,3)->isNull())
				{
					str += ",NULL";
				}
				else
				{
					CString ss;
					ss.Format(_T(",%f"),table->getData(i,3)->toDouble());
					str += ss;
				}

				AfxMessageBox(str);
			}
			
			YLR::YDataInterface::releaseDataTable(table);
		}
		//d1.beginTransaction();
		d1.executeSqlWithOutDt("INSERT INTO tb_test (text1) VALUES ('���')");
		//d1.rollbackTransaction();
		d1.disconnectDataBase();
	}
}
