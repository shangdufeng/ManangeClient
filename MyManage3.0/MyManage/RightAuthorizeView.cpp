// RightAuthorizeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthorizeView.h"
#include "afxdialogex.h"


// CRightAuthorizeView �Ի���

IMPLEMENT_DYNAMIC(CRightAuthorizeView, CDialog)

CRightAuthorizeView::CRightAuthorizeView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthorizeView::IDD, pParent)
{

}

CRightAuthorizeView::~CRightAuthorizeView()
{
}

void CRightAuthorizeView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRightAuthorizeView, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightAuthorizeView ��Ϣ�������


void CRightAuthorizeView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CRect rect;
	GetClientRect(&rect);
	dc.FillRect(rect,&Brush);
	dc.SelectObject(pOldBrush);
}
