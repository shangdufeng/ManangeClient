// RightQueMessView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueMessView.h"
#include "afxdialogex.h"


// CRightQueMessView �Ի���

IMPLEMENT_DYNAMIC(CRightQueMessView, CDialog)

CRightQueMessView::CRightQueMessView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueMessView::IDD, pParent)
{

}

CRightQueMessView::~CRightQueMessView()
{
}

void CRightQueMessView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERMESS, m_usermess);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Control(pDX, IDC_SUB, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueMessView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightQueMessView ��Ϣ�������


BOOL CRightQueMessView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_usermess.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_usermess.InsertColumn(0,_T("����/����"),LVCFMT_CENTER,50);
	m_usermess.InsertColumn(1,_T("����"),LVCFMT_CENTER,50);
	m_usermess.InsertColumn(2,_T("����ʱ��"),LVCFMT_CENTER,100);
	m_usermess.InsertColumn(3,_T("ժҪ"),LVCFMT_LEFT,100);
	m_usermess.InsertColumn(4,_T("�Ѷ�"),LVCFMT_LEFT,50);
	m_usermess.InsertItem(0,_T("1"));
	m_usermess.InsertItem(1,_T("2"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("�����ѯ��"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightQueMessView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightQueMessView::OnPaint()
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


HBRUSH CRightQueMessView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
