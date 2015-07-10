// RightAuthCS1View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthCS1View.h"
#include "afxdialogex.h"


// CRightAuthCS1View �Ի���

IMPLEMENT_DYNAMIC(CRightAuthCS1View, CDialog)

CRightAuthCS1View::CRightAuthCS1View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthCS1View::IDD, pParent)
{

}

CRightAuthCS1View::~CRightAuthCS1View()
{
}

void CRightAuthCS1View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERLIST, m_userlist);
	DDX_Control(pDX, IDC_CHOUSERLIST, m_chouserlist);
	DDX_Control(pDX, IDC_DOCLIST, m_doclist);
	DDX_Control(pDX, IDC_CHODOCLIST, m_chodoclist);
	DDX_Control(pDX, IDC_CSMLIST, m_csmlist);
	DDX_CBString(pDX, IDC_QUEUSERTYPE, m_queusertype);
	DDX_Text(pDX, IDC_QUEUSERTEXT, m_queusertext);
	DDX_CBString(pDX, IDC_QUEDOCTYPE, m_quedoctype);
	DDX_Text(pDX, IDC_QUEDOCTEXT, m_quedoctext);
	DDX_Control(pDX, IDC_BTN_QUEUSER, m_BtnSelUser);
	DDX_Control(pDX, IDC_ADDUSER, m_BtnAddUser);
	DDX_Control(pDX, IDC_DELUSER, m_BtnDelUser);
	DDX_Control(pDX, IDC_BTN_QUEDOC, m_BtnSelDoc);
	DDX_Control(pDX, IDC_ADDDOC, m_BtnAddDoc);
	DDX_Control(pDX, IDC_DELDOC, m_BtnDelDoc);
	DDX_Control(pDX, IDC_BTN_QUEMAN, m_BtnSelMan);
	DDX_Control(pDX, IDC_QUEUSERTYPE, m_QueTypeUser);
	DDX_Control(pDX, IDC_QUEDOCTYPE, m_QueTypeDoc);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
	DDX_Control(pDX, IDC_GROUP2, m_Group2);
}


BEGIN_MESSAGE_MAP(CRightAuthCS1View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthCS1View ��Ϣ�������


BOOL CRightAuthCS1View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_userlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	/*m_userlist.InsertColumn(0,_T("���"),LVCFMT_CENTER,40);*/
	m_userlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_userlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_chouserlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	/*m_chouserlist.InsertColumn(0,_T("���"),LVCFMT_CENTER,40);*/
	m_chouserlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_chouserlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_doclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_doclist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_doclist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_chodoclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chodoclist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_chodoclist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_csmlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_csmlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_csmlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_QueTypeUser.SetCurSel(0);
	m_QueTypeDoc.SetCurSel(0);

	m_BtnSelUser.SetFlat(FALSE);
	m_BtnSelUser.DrawTransparent(TRUE);
	m_BtnSelUser.SetTooltipText(_T("�����ѯ��"));

	m_BtnAddUser.SetFlat(FALSE);
	m_BtnAddUser.DrawTransparent(TRUE);
	m_BtnAddUser.SetTooltipText(_T("����û�"));

	m_BtnDelUser.SetFlat(FALSE);
	m_BtnDelUser.DrawTransparent(TRUE);
	m_BtnDelUser.SetTooltipText(_T("�޳��û�"));

	m_BtnSelDoc.SetFlat(FALSE);
	m_BtnSelDoc.DrawTransparent(TRUE);
	m_BtnSelDoc.SetTooltipText(_T("�����ѯ��"));

	m_BtnAddDoc.SetFlat(FALSE);
	m_BtnAddDoc.DrawTransparent(TRUE);
	m_BtnAddDoc.SetTooltipText(_T("���ҽ��"));

	m_BtnDelDoc.SetFlat(FALSE);
	m_BtnDelDoc.DrawTransparent(TRUE);
	m_BtnDelDoc.SetTooltipText(_T("�޳�ҽ��"));

	m_BtnSelMan.SetFlat(FALSE);
	m_BtnSelMan.DrawTransparent(TRUE);
	m_BtnSelMan.SetTooltipText(_T("�����ѯ"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	m_Group2.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightAuthCS1View::OnPaint()
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


HBRUSH CRightAuthCS1View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_CSM_NAME))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_CSM_CELLNUM))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightAuthCS1View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEMAN)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
