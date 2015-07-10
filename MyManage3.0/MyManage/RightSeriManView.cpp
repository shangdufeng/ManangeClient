// RightSeriManView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightSeriManView.h"
#include "afxdialogex.h"


// CRightSeriManView �Ի���

IMPLEMENT_DYNAMIC(CRightSeriManView, CDialog)

CRightSeriManView::CRightSeriManView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightSeriManView::IDD, pParent)
{

}

CRightSeriManView::~CRightSeriManView()
{
}

void CRightSeriManView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SERIMAN, m_seriman);
	DDX_Control(pDX, IDC_BUTTON8, m_Add);
	DDX_Control(pDX, IDC_BUTTON1, m_Del);
	DDX_Control(pDX, IDC_BUTTON7, m_Sub);
}


BEGIN_MESSAGE_MAP(CRightSeriManView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightSeriManView ��Ϣ�������


BOOL CRightSeriManView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_seriman.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_seriman.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_seriman.InsertColumn(1,_T("���к�"),LVCFMT_CENTER,200);
	m_seriman.InsertColumn(2,_T("�豸����"),LVCFMT_CENTER,100);
	m_seriman.InsertColumn(3,_T("�ϴ���"),LVCFMT_CENTER,100);
	m_seriman.InsertColumn(4,_T("�ϴ�ʱ��"),LVCFMT_CENTER,100);

	m_Add.DrawTransparent(TRUE);
	m_Add.SetFlat(FALSE);
	m_Add.SetTooltipText(_T("���"));

	m_Del.DrawTransparent(TRUE);
	m_Del.SetFlat(FALSE);
	m_Del.SetTooltipText(_T("ɾ��"));

	m_Sub.DrawTransparent(TRUE);
	m_Sub.SetFlat(FALSE);
	m_Sub.SetTooltipText(_T("�ύ"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightSeriManView::OnPaint()
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
	dc.Rectangle(CRect(0,0,720,530));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}


HBRUSH CRightSeriManView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd->GetDlgCtrlID()==IDC_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}
