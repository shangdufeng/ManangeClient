// RightWelView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightWelView.h"
#include "afxdialogex.h"


// CRightWelView �Ի���

IMPLEMENT_DYNAMIC(CRightWelView, CDialog)

CRightWelView::CRightWelView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightWelView::IDD, pParent)
{
    m_Brush.CreateSolidBrush(theApp.m_RightColr);
	m_MsgFont.CreatePointFont(150,_T("����"));
	m_HintFont.CreatePointFont(150,_T("����"));
	m_WelFont.CreatePointFont(200,_T("����"));
}

CRightWelView::~CRightWelView()
{
}

void CRightWelView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRightWelView, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightWelView ��Ϣ�������


HBRUSH CRightWelView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_WEL)) 
	{ 
		pDC->SelectObject(&m_WelFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_INFO)) 
	{ 
		pDC->SelectObject(&m_HintFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_INFOTEXT)) 
	{ 
		pDC->SelectObject(&m_MsgFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	return m_Brush;
	/*return hbr;*/
}
