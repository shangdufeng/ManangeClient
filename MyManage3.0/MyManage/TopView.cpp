// TopView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "TopView.h"
#include "afxdialogex.h"


// CTopView �Ի���

IMPLEMENT_DYNAMIC(CTopView, CDialog)

CTopView::CTopView(CWnd* pParent /*=NULL*/)
	: CDialog(CTopView::IDD, pParent)
	, m_nWidth(0)
{
	m_BrushLeft.CreateSolidBrush(theApp.m_LeftColr);
	m_BrushRight.CreateSolidBrush(theApp.m_RightColr);
	/*m_MoveMode=FALSE;*/
}

CTopView::~CTopView()
{
}

void CTopView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
 	DDX_Control(pDX, IDC_BTN_MIN, m_BtnMin);
 	DDX_Control(pDX, IDC_BTN_OFF, m_BtnOff);
}


BEGIN_MESSAGE_MAP(CTopView, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
//	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
//ON_WM_LBUTTONDOWN()
ON_WM_TIMER()
ON_WM_PAINT()
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_BN_CLICKED(IDC_BTN_OFF, &CTopView::OnBnClickedBtnOff)
ON_BN_CLICKED(IDC_BTN_MIN, &CTopView::OnBnClickedBtnMin)
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CTopView ��Ϣ�������


HBRUSH CTopView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd->GetDlgCtrlID()==IDC_LINK)
	{
		pDC->SetBkMode(TRANSPARENT);
		return m_BrushRight/*(HBRUSH)GetStockObject(HOLLOW_BRUSH)*/;
	}
	return m_BrushRight;
	/*return hbr;*/
}


BOOL CTopView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_BTN_MIN)->MoveWindow(735,0,20,20);
	m_BtnMin.DrawTransparent(TRUE);
	m_BtnMin.SetBitmaps(IDB_BIT_MIN1,RGB(255,255,255));
	m_BtnMin.SetTooltipText(_T("��С��"));

	GetDlgItem(IDC_BTN_OFF)->MoveWindow(760,0,20,20);
	m_BtnOff.DrawTransparent(TRUE);
	m_BtnOff.SetBitmaps(IDB_BIT_OFF1,RGB(255,255,255));
	m_BtnOff.SetTooltipText(_T("�ر�"));
	GetDlgItem(IDC_LINK)->SetWindowPos(0,291,2,200,23,0);
	GetDlgItem(IDC_LINK)->GetWindowRect(m_Rc);
	ScreenToClient(&m_Rc);

	EnableToolTips(TRUE);
	m_tt.Create(this);
	m_tt.Activate(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CTopView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_BTN_MIN)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_OFF)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


//void CTopView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	m_Point1=point;
//	m_MoveMode=TRUE;
//	CDialog::OnLButtonDown(nFlags, point);
//}



//void CTopView::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	m_MoveMode=FALSE;
//	CDialog::OnLButtonUp(nFlags, point);
//}


//void CTopView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	if(m_MoveMode)
//	{
//		CRect rt;
//		GetWindowRect(rt);
//		m_PosOri.x=rt.left;
//		m_PosOri.y=rt.top;
//
//		m_Point2=point;
//		CPoint Pos2;
//		double xDistance;
//		double yDistance;
//		xDistance=m_Point2.x-m_Point1.x;
//		yDistance=m_Point2.y-m_Point1.y;
//
//
//		Pos2.x=m_PosOri.x+xDistance;
//		Pos2.y=m_PosOri.y+yDistance;
//
//		SetWindowPos(NULL,Pos2.x,Pos2.y,0,0,SWP_NOSIZE);
//		//m_Point1=m_Point2;
//
//
//	}
//	CDialog::OnMouseMove(nFlags, point);
//}




void CTopView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nWidth += 5;
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(150,_T("�����п�"),NULL);
	CFont* pOldFont=dc.SelectObject(&font);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rc,rc1;
	GetClientRect(rc1);
	CString str=_T("��������˾��ӭ����");
	
	rc.left=rc1.Width()/2-dc.GetTextExtent(str).cx-20;
	rc.top=rc1.Height()/2-tm.tmHeight/2;
	rc.right=rc.left+m_nWidth;
	rc.bottom=rc.top+tm.tmHeight;

// 	CBrush* Brush=CBrush::FromHandle((HBRUSH)GetStockObject(HOLLOW_BRUSH));
// 	CBrush* pOldBrush=dc.SelectObject(Brush);
// 	dc.SetTextColor(RGB(0,0,0));
	dc.SetBkMode(TRANSPARENT);
	dc.DrawText(str,rc,DT_LEFT);

	dc.SelectObject(pOldFont);
	
/*	dc.SelectObject(pOldBrush);*/
// 	if(dc.GetTextExtent(str).cx<m_nWidth)
// 	{
// 		dc.SetTextColor(RGB(255,0,0));IDD_LEFT_MESSSEND
// 		dc.TextOut(rc.left,rc.right,str);
// 		m_nWidth=0;
// 	}
	
	CDialog::OnTimer(nIDEvent);
}


void CTopView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	SetTimer(1,100,NULL);
}


void CTopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(point.x>m_Rc.left&&point.x<m_Rc.right&&point.y>m_Rc.top&&point.y<m_Rc.bottom)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		ShellExecute(NULL,_T("open"),TEXT("http://tr24h.com"),NULL,NULL,SW_NORMAL);
		
	}
/*	GetParent()->OnLButtonDown(nFlags,point);*/
	else
	{
	    theApp.m_MyManageDlg->m_Point1=point;
	    theApp.m_MyManageDlg->m_MoveMode=TRUE;
	}
	CDialog::OnLButtonDown(nFlags, point);
}


void CTopView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
// 	EnableToolTips(TRUE);
// 	m_tt.Create(this);
// 	m_tt.Activate(TRUE);
	if(PtInRect(m_Rc,point)/*point.x>m_Rc.left&&point.x<m_Rc.right&&point.y>m_Rc.top&&point.y<m_Rc.bottom*/)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
// 		CClientDC dc(this);
// 		CFont font;
// 		font.CreatePointFont(150,_T("�����п�"),NULL);
// 		CFont *pOldFont = dc.SelectObject(&font);
// 		dc.TextOut(291,2,_T("��������˾��ӭ����"));
// 		
// 		dc.SelectObject(pOldFont);

 	/*	CWnd* pW=GetDlgItem(IDC_LINK);*/
		m_tt.AddTool(this,_T("http://tr24h.com"));
	
	}
	else
	{
		m_tt.DelTool(this);
	}
	theApp.m_MyManageDlg->OnMouseMove(nFlags,point);

	CDialog::OnMouseMove(nFlags, point);
}


BOOL CTopView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
// 	if (WM_MOUSEMOVE==pMsg->message)
// 	{
// 		if(PtInRect(m_Rc,theApp.m_HintViewPoint)/*point.x>m_Rc.left&&point.x<m_Rc.right&&point.y>m_Rc.top&&point.y<m_Rc.bottom*/)
// 		{
// 			SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
// 			// 		CClientDC dc(this);
// 			// 		CFont font;
// 			// 		font.CreatePointFont(150,_T("�����п�"),NULL);
// 			// 		CFont *pOldFont = dc.SelectObject(&font);
// 			// 		dc.TextOut(291,2,_T("��������˾��ӭ����"));
// 			// 		
// 			// 		dc.SelectObject(pOldFont);
// 			theApp.m_pWebView->MoveWindow(theApp.m_HintViewPoint.x,theApp.m_HintViewPoint.y,100,60);
// 			theApp.m_pWebView->ShowWindow(SW_SHOW);
// 
// 		}
// 		else
// 		{
// 			theApp.m_pWebView->ShowWindow(SW_HIDE);
// 		}
// 	}
	m_tt.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}


void CTopView::OnBnClickedBtnOff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CTopView::OnBnClickedBtnMin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetParent()->ShowWindow(SW_MINIMIZE);
}


void CTopView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	theApp.m_MyManageDlg->m_MoveMode=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}
