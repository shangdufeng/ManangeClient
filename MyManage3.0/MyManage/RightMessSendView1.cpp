// RightMessSendView1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightMessSendView1.h"
#include "afxdialogex.h"


// CRightMessSendView1 �Ի���

IMPLEMENT_DYNAMIC(CRightMessSendView1, CDialog)

CRightMessSendView1::CRightMessSendView1(CWnd* pParent /*=NULL*/)
	: CDialog(CRightMessSendView1::IDD, pParent)
{

}

CRightMessSendView1::~CRightMessSendView1()
{
}

void CRightMessSendView1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Btn1);
	DDX_Control(pDX, IDC_BTN_SEND, m_Btn2);
	DDX_Control(pDX, IDC_SYSMESSLIST, m_sendmess);
	DDX_Control(pDX, IDC_COMBO1, m_Cmb1);
	DDX_Control(pDX, IDC_COMBO4, m_Cmb2);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Data);
	DDX_Control(pDX, IDC_TIME, m_Time);
}


BEGIN_MESSAGE_MAP(CRightMessSendView1, CDialog)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK1, &CRightMessSendView1::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CRightMessSendView1 ��Ϣ�������


void CRightMessSendView1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,783,659),&Brush);
	dc.SelectObject(pOldBrush);
}


BOOL CRightMessSendView1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_sendmess.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_sendmess.InsertColumn(0,_T("����"),LVCFMT_CENTER,100);
	m_sendmess.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,300);
	m_sendmess.InsertColumn(2,_T("�Ա�"),LVCFMT_CENTER,100);

	m_Cmb1.SetCurSel(0);
	m_Cmb2.SetCurSel(1);

	m_Btn1.SetFlat(FALSE);
	m_Btn1.DrawTransparent(TRUE);
	m_Btn1.SetTooltipText(_T("��ѯ"));

	m_Btn2.SetFlat(FALSE);
	m_Btn2.DrawTransparent(TRUE);
	m_Btn2.SetTooltipText(_T("����"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);

	m_Data.EnableWindow(FALSE);
	m_Time.EnableWindow(FALSE);

	/*GetDlgItem(IDC_TIME)->EnableWindow(FALSE);*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightMessSendView1::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_SEND)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightMessSendView1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


void CRightMessSendView1::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(IsDlgButtonChecked(IDC_CHECK1)==BST_CHECKED)
	{
		m_Data.EnableWindow(TRUE);
	    m_Time.EnableWindow(TRUE);
	}
	else
	{
		m_Data.EnableWindow(FALSE);
		m_Time.EnableWindow(FALSE);
	}
}
