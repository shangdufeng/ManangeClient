// RightChgSeriView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgSeriView.h"
#include "afxdialogex.h"


// CRightChgSeriView �Ի���

IMPLEMENT_DYNAMIC(CRightChgSeriView, CDialog)

CRightChgSeriView::CRightChgSeriView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgSeriView::IDD, pParent)
{

}

CRightChgSeriView::~CRightChgSeriView()
{
}

void CRightChgSeriView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERIID, m_seriID);
	DDX_Control(pDX, IDC_USERINFO, m_userinfo);
	DDX_Control(pDX, IDC_QUE, m_Btn);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightChgSeriView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightChgSeriView ��Ϣ�������


BOOL CRightChgSeriView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_userinfo.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE);
	m_userinfo.InsertColumn(0,_T("����"),0,60);
	m_userinfo.InsertColumn(1,_T("�ֻ���"),0,100);
	m_userinfo.InsertColumn(2,_T("ע��ʱ��"),0,100);
	m_userinfo.InsertColumn(3,_T("��Լҽ��"),0,80);
	m_userinfo.InsertColumn(4,_T("������ϵ��"),0,100);
	m_userinfo.InsertColumn(5,_T("������ϵ�˺���"),0,120);

	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetFlat(FALSE);
	m_Btn.SetTooltipText(_T("��ѯ"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightChgSeriView::OnPaint()
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


HBRUSH CRightChgSeriView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightChgSeriView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
