// RightAuthTech1View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthTech1View.h"
#include "afxdialogex.h"


// CRightAuthTech1View �Ի���

IMPLEMENT_DYNAMIC(CRightAuthTech1View, CDialog)

CRightAuthTech1View::CRightAuthTech1View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthTech1View::IDD, pParent)
{

}

CRightAuthTech1View::~CRightAuthTech1View()
{
}

void CRightAuthTech1View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TMLIST, m_tmlist);
	DDX_Control(pDX, IDC_CHOTMLIST, m_chotmlist);
	DDX_Control(pDX, IDC_COMBO1, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUETM, m_BtnQueTech);
	DDX_Control(pDX, IDC_ADDTM, m_AddTech);
	DDX_Control(pDX, IDC_DELTM, m_DelTech);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthTech1View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthTech1View ��Ϣ�������


BOOL CRightAuthTech1View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tmlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_tmlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_tmlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_chotmlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chotmlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_chotmlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQueTech.DrawTransparent(TRUE);
	m_BtnQueTech.SetFlat(FALSE);
	m_BtnQueTech.SetTooltipText(_T("��ѯ��ʦ����"));

	m_AddTech.DrawTransparent(TRUE);
	m_AddTech.SetFlat(FALSE);
	m_AddTech.SetTooltipText(_T("��Ӽ�ʦ����"));

	m_DelTech.DrawTransparent(TRUE);
	m_DelTech.SetFlat(FALSE);
	m_DelTech.SetTooltipText(_T("�޳���ʦ����"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightAuthTech1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,702,445),&Brush);
	dc.SelectObject(pOldBrush);
}


HBRUSH CRightAuthTech1View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthTech1View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUETM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELTM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
