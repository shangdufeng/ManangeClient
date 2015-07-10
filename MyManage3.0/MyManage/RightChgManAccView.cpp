// RightChgManAccView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgManAccView.h"
#include "afxdialogex.h"


// CRightChgManAccView �Ի���

IMPLEMENT_DYNAMIC(CRightChgManAccView, CDialog)

CRightChgManAccView::CRightChgManAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgManAccView::IDD, pParent)
{

}

CRightChgManAccView::~CRightChgManAccView()
{
}

void CRightChgManAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_MANLIST, m_manlist);
	DDX_Control(pDX, IDC_QUETYPE, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUE, m_BtnQue);
	DDX_Control(pDX, IDC_BUTTON2, m_BtnOK);
	DDX_Control(pDX, IDC_SUB, m_BtnSub);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
}


BEGIN_MESSAGE_MAP(CRightChgManAccView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightChgManAccView ��Ϣ�������


BOOL CRightChgManAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_manlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_manlist.InsertColumn(0,_T("����"),LVCFMT_CENTER,100);
	m_manlist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);
	m_manlist.InsertColumn(2,_T("����Ա����"),LVCFMT_CENTER,150);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("��ѯ"));

	m_BtnOK.DrawTransparent(TRUE);
	m_BtnOK.SetFlat(FALSE);
	m_BtnOK.SetTooltipText(_T("���ȷ��"));

	m_BtnSub.DrawTransparent(TRUE);
	m_BtnSub.SetFlat(FALSE);
	m_BtnSub.SetTooltipText(_T("����ύ"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightChgManAccView::OnPaint()
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


HBRUSH CRightChgManAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_SELMAN))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_MANTYPE))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightChgManAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON2)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
