// HeadTextView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "HeadTextView.h"
#include "afxdialogex.h"


// CHeadTextView �Ի���

IMPLEMENT_DYNAMIC(CHeadTextView, CDialog)

CHeadTextView::CHeadTextView(CWnd* pParent /*=NULL*/)
	: CDialog(CHeadTextView::IDD, pParent)
{
	m_head.CreatePointFont(350,_T("����"));
	m_head1.CreatePointFont(300,_T("����"));
}

CHeadTextView::~CHeadTextView()
{
}

void CHeadTextView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHeadTextView, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHeadTextView ��Ϣ�������


HBRUSH CHeadTextView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_HEAD)) 
	{ 
		pDC->SelectObject(&m_head);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if ((pWnd->GetDlgCtrlID()==IDC_HEAD1)) 
	{ 
		pDC->SelectObject(&m_head1);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	return hbr;
}


BOOL CHeadTextView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_HEAD)->MoveWindow(220,50,600,50);
	GetDlgItem(IDC_HEAD1)->MoveWindow(431,100,200,50);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CHeadTextView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BIT_HEAD); 
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	/*dc.Rectangle(CRect(0,0,240,683));  */
	dc.FillRect(CRect(0,0,1200,200),&brush);
	dc.SelectObject(pOldBrush);
}
