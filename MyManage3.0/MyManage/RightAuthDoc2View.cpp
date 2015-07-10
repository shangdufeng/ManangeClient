// RightAuthDoc2View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthDoc2View.h"
#include "afxdialogex.h"


// CRightAuthDoc2View �Ի���

IMPLEMENT_DYNAMIC(CRightAuthDoc2View, CDialog)

CRightAuthDoc2View::CRightAuthDoc2View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthDoc2View::IDD, pParent)
{

}

CRightAuthDoc2View::~CRightAuthDoc2View()
{
}

void CRightAuthDoc2View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DP, m_dplist);
	DDX_Control(pDX, IDC_CHODP, m_chodplist);
	DDX_CBString(pDX, IDC_QUEDPTYPE, m_quedptype);
	DDX_Text(pDX, IDC_QUEDPTEXT, m_quedptext);
	DDX_Control(pDX, IDC_QUEDPTYPE, m_QueType);
	//  DDX_Control(pDX, IDC_BTN_QUEDP, m_);
	DDX_Control(pDX, IDC_BTN_QUEDP, m_BtnQue);
	DDX_Control(pDX, IDC_BUTTON1, m_Add);
	DDX_Control(pDX, IDC_DEL, m_Del);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthDoc2View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthDoc2View ��Ϣ�������


BOOL CRightAuthDoc2View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_dplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_dplist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_dplist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_chodplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chodplist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_chodplist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("��ѯ"));

	m_Add.DrawTransparent(TRUE);
	m_Add.SetFlat(FALSE);
	m_Add.SetTooltipText(_T("���ȫ��ҽ��"));

	m_Del.DrawTransparent(TRUE);
	m_Del.SetFlat(FALSE);
	m_Del.SetTooltipText(_T("�޳�ȫ��ҽ��"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightAuthDoc2View::OnPaint()
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


HBRUSH CRightAuthDoc2View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthDoc2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEDP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DEL)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
