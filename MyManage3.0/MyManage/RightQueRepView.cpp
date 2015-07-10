// RightQueRepView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueRepView.h"
#include "afxdialogex.h"


// CRightQueRepView �Ի���

IMPLEMENT_DYNAMIC(CRightQueRepView, CDialog)

CRightQueRepView::CRightQueRepView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueRepView::IDD, pParent)
{

}

CRightQueRepView::~CRightQueRepView()
{
}

void CRightQueRepView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_REP, m_rep);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_CBString(pDX, IDC_COMBO1, m_reptype);
	DDX_Control(pDX, IDC_COMBO1, m_index);
	DDX_Control(pDX, IDC_SUB, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueRepView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightQueRepView ��Ϣ�������


BOOL CRightQueRepView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_rep.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_rep.InsertColumn(0,_T("����"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(1,_T("ʱ��"),LVCFMT_CENTER,60);
	m_rep.InsertColumn(2,_T("�쳣"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(3,_T("ǩ��"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(4,_T("ҽ��"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(5,_T("�Ѷ�"),LVCFMT_CENTER,50);

	m_rep.InsertItem(0,_T(""));
	m_rep.InsertItem(1,_T(""));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("�����ѯ��"));

	m_index.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightQueRepView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightQueRepView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if (pWnd->GetDlgCtrlID()==IDC_STATIC)
	{

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


void CRightQueRepView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	CPen   Pen;
	Pen.CreatePen(PS_SOLID,1,theApp.m_LineColor);
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CPen*   pOldPen=dc.SelectObject(&Pen);
	dc.Rectangle(CRect(0,0,726,445));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}
