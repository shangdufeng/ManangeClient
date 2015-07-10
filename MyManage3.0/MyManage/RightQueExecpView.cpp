// RightQueExecpView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueExecpView.h"
#include "afxdialogex.h"


// CRightQueExecpView �Ի���

IMPLEMENT_DYNAMIC(CRightQueExecpView, CDialog)

CRightQueExecpView::CRightQueExecpView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueExecpView::IDD, pParent)
{

}

CRightQueExecpView::~CRightQueExecpView()
{
}

void CRightQueExecpView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXCEPINFO, m_excepinfo);
	DDX_Control(pDX, IDC_STARTDATE, m_start);
	DDX_Control(pDX, IDC_ENDDATE, end);
	DDX_Control(pDX, IDC_QUE, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueExecpView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightQueExecpView ��Ϣ�������


BOOL CRightQueExecpView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_excepinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_excepinfo.InsertColumn(0,_T("����ʱ��"),LVCFMT_CENTER,100);
	m_excepinfo.InsertColumn(1,_T("�쳣����"),LVCFMT_CENTER,100);
	m_excepinfo.InsertColumn(2,_T("��Ͻ��"),LVCFMT_CENTER,100);
	m_excepinfo.InsertColumn(3,_T("ǩ��ҽʦ"),LVCFMT_CENTER,100);
	m_excepinfo.InsertColumn(4,_T("�����ļ���"),LVCFMT_CENTER,100);

	m_excepinfo.InsertItem(0,_T("1"));
	m_excepinfo.InsertItem(1,_T("2"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("�����ѯ��"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightQueExecpView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightQueExecpView::OnPaint()
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


HBRUSH CRightQueExecpView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
