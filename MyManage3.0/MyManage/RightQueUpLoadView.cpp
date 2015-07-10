// RightQueUpLoadView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueUpLoadView.h"
#include "afxdialogex.h"


// CRightQueUpLoadView �Ի���

IMPLEMENT_DYNAMIC(CRightQueUpLoadView, CDialog)

CRightQueUpLoadView::CRightQueUpLoadView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueUpLoadView::IDD, pParent)
{

}

CRightQueUpLoadView::~CRightQueUpLoadView()
{
}

void CRightQueUpLoadView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UPLOADINFO, m_uploadinfo);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Control(pDX, IDC_SUB, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueUpLoadView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightQueUpLoadView ��Ϣ�������


BOOL CRightQueUpLoadView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_uploadinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_uploadinfo.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_uploadinfo.InsertColumn(1,_T("�ϴ�ʱ��"),LVCFMT_CENTER,100);
	m_uploadinfo.InsertColumn(2,_T("�ϴ�����"),LVCFMT_CENTER,150);
	m_uploadinfo.InsertColumn(3,_T("�ļ���С"),LVCFMT_CENTER,100);
	m_uploadinfo.InsertColumn(4,_T("�ϴ���ʽ"),LVCFMT_CENTER,100);


	m_uploadinfo.InsertItem(0,_T("1"));
	m_uploadinfo.InsertItem(1,_T("2"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("�����ѯ��"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightQueUpLoadView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightQueUpLoadView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CRightQueUpLoadView::OnPaint()
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
