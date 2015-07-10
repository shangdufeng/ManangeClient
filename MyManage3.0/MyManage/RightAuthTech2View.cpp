// RightAuthTech2View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthTech2View.h"
#include "afxdialogex.h"


// CRightAuthTech2View �Ի���

IMPLEMENT_DYNAMIC(CRightAuthTech2View, CDialog)

CRightAuthTech2View::CRightAuthTech2View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthTech2View::IDD, pParent)
{

}

CRightAuthTech2View::~CRightAuthTech2View()
{
}

void CRightAuthTech2View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TPLIST, m_tplist);
	DDX_Control(pDX, IDC_CHOTPLIST, m_chotplist);
	DDX_CBString(pDX, IDC_QUETECHTYPE, m_quetechtype);
	DDX_Text(pDX, IDC_QUETECHTEXT, m_quetechtext);
	DDX_Control(pDX, IDC_QUETECHTYPE, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUETP, m_BtnQue);
	DDX_Control(pDX, IDC_ADDTP, m_AddTech);
	DDX_Control(pDX, IDC_DELTP, m_DelTech);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthTech2View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthTech2View ��Ϣ�������


BOOL CRightAuthTech2View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_tplist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_tplist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_chotplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chotplist.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_chotplist.InsertColumn(1,_T("�˺�"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("�����ѯ"));

	m_AddTech.DrawTransparent(TRUE);
	m_AddTech.SetFlat(FALSE);
	m_AddTech.SetTooltipText(_T("��Ӽ�ʦ"));

	m_DelTech.DrawTransparent(TRUE);
	m_DelTech.SetFlat(FALSE);
	m_DelTech.SetTooltipText(_T("�޳���ʦ"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightAuthTech2View::OnPaint()
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


HBRUSH CRightAuthTech2View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthTech2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUETP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
