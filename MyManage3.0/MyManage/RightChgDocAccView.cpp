// RightChgDocAccView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgDocAccView.h"
#include "afxdialogex.h"


// CRightChgDocAccView �Ի���

IMPLEMENT_DYNAMIC(CRightChgDocAccView, CDialog)

CRightChgDocAccView::CRightChgDocAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgDocAccView::IDD, pParent)
{

}

CRightChgDocAccView::~CRightChgDocAccView()
{
}

void CRightChgDocAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOCINFO, m_docinfo);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_BTN_INFO, m_Btn1);
	DDX_Control(pDX, IDC_BTN_REC, m_Btn2);
	DDX_Control(pDX, IDC_BTN_MESS, m_Btn);
	DDX_Control(pDX, IDC_QUE, m_Btn4);
	DDX_Control(pDX, IDC_QUETYPE, m_QueType);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightChgDocAccView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_INFO, &CRightChgDocAccView::OnBnClickedBtnInfo)
	ON_BN_CLICKED(IDC_BTN_REC, &CRightChgDocAccView::OnBnClickedBtnRec)
	ON_BN_CLICKED(IDC_BTN_MESS, &CRightChgDocAccView::OnBnClickedBtnMess)
END_MESSAGE_MAP()


// CRightChgDocAccView ��Ϣ�������


BOOL CRightChgDocAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_docinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_docinfo.InsertColumn(0,_T("����"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(1,_T("�Ա�"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(2,_T("�˺�"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(3,_T("���֤��"),LVCFMT_CENTER,100);

	m_docinfo.InsertItem(0,_T("1"));
	m_docinfo.InsertItem(1,_T("2"));

	m_QueType.SetCurSel(1);

	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn4.SetFlat(FALSE);
	m_Btn4.DrawTransparent(TRUE);
	m_Btn4.SetTooltipText(_T("�����ѯ��"));

	CRect rc(30,206,756,651);
	///////////////////����ҽ��������Ϣ����/////////////////////////
	m_RightDocBasView.Create(IDD_DOC_BAS,this);
	m_RightDocBasView.MoveWindow(rc);
	m_RightDocBasView.ShowWindow(SW_SHOW);

	//////////////////����ҽ����ϼ�¼����//////////////////////////
	m_RightDocDiagView.Create(IDD_DOC_DIAG,this);
	m_RightDocDiagView.MoveWindow(rc);
	m_RightDocDiagView.ShowWindow(SW_HIDE);

	/////////////////����ҽ����Ϣ����////////////////////////////////
	m_RightDocMessView.Create(IDD_DOC_MESS,this);
	m_RightDocMessView.MoveWindow(rc);
	m_RightDocMessView.ShowWindow(SW_HIDE);

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightChgDocAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_INFO)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_REC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_MESS)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightChgDocAccView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,783,659),&Brush);
	dc.SelectObject(pOldBrush);
}


HBRUSH CRightChgDocAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightChgDocAccView::OnBnClickedBtnInfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RightDocBasView.ShowWindow(SW_SHOW);
	m_RightDocDiagView.ShowWindow(SW_HIDE);
	m_RightDocMessView.ShowWindow(SW_HIDE);
}


void CRightChgDocAccView::OnBnClickedBtnRec()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RightDocDiagView.ShowWindow(SW_SHOW);
	m_RightDocBasView.ShowWindow(SW_HIDE);
	m_RightDocMessView.ShowWindow(SW_HIDE);

}


void CRightChgDocAccView::OnBnClickedBtnMess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_RightDocMessView.ShowWindow(SW_SHOW);
	m_RightDocDiagView.ShowWindow(SW_HIDE);
	m_RightDocBasView.ShowWindow(SW_HIDE);

}
