// RightDocDiagView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightDocDiagView.h"
#include "afxdialogex.h"


// CRightDocDiagView �Ի���

IMPLEMENT_DYNAMIC(CRightDocDiagView, CDialog)

CRightDocDiagView::CRightDocDiagView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightDocDiagView::IDD, pParent)
{

}

CRightDocDiagView::~CRightDocDiagView()
{
}

void CRightDocDiagView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIAG, m_diag);
	//  DDX_DateTimeCtrl(pDX, IDC_STARTDATE, m_startdate);
	DDX_Control(pDX, IDC_ENDDATE, m_enddate);
	DDX_Control(pDX, IDC_STARTDATE, m_startdate);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_QUE, m_Btn);
	DDX_Control(pDX, IDC_BUTTON2, m_Btn1);
	DDX_Control(pDX, IDC_BUTTON3, m_Btn2);
	DDX_Control(pDX, IDC_QUETYPE, m_Mem);
}


BEGIN_MESSAGE_MAP(CRightDocDiagView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightDocDiagView ��Ϣ�������


BOOL CRightDocDiagView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_diag.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_diag.InsertColumn(0,_T("����"),LVCFMT_CENTER,60);
	m_diag.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_diag.InsertColumn(2,_T("��Ͻ��"),LVCFMT_CENTER,100);

	m_diag.InsertItem(0,_T(""));
	m_diag.InsertItem(1,_T(""));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("�����ѯ��"));

	m_Btn1.SetFlat(FALSE);
	m_Btn1.DrawTransparent(TRUE);
	m_Btn1.SetTooltipText(_T("����޸ģ�"));

	m_Btn2.SetFlat(FALSE);
	m_Btn2.DrawTransparent(TRUE);
	m_Btn2.SetTooltipText(_T("����ύ��"));

	m_Mem.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightDocDiagView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON2)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON3)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightDocDiagView::OnPaint()
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


HBRUSH CRightDocDiagView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
