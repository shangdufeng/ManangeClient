

// MyManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "MyManageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyManageDlg �Ի���




CMyManageDlg::CMyManageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyManageDlg::IDD, pParent)

	, m_Point1(0)
	, m_Point2(0)
	, m_MoveMode(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_PosOri.x=200;
	m_PosOri.y=100;
	theApp.m_MyManageDlg=this;
	
	
	/*theApp.m_MyManageView=this;*/
}

void CMyManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_MIN, m_BtnMin);
	DDX_Control(pDX, IDC_BTN_OFF, m_BtnOff);
}

BEGIN_MESSAGE_MAP(CMyManageDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_OFF, &CMyManageDlg::OnBnClickedBtnOff)
	ON_BN_CLICKED(IDC_BTN_MIN, &CMyManageDlg::OnBnClickedBtnMin)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	/*ON_BN_CLICKED(IDC_BTN_LOGIN, &CMyManageDlg::OnBnClickedBtnLogin)*/
END_MESSAGE_MAP()


// CMyManageDlg ��Ϣ�������

BOOL CMyManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BIT_BK);
	m_Brush.CreatePatternBrush(&bmp);
	bmp.DeleteObject();

	SetWindowPos(NULL,200,100,1023,683,0);
	
	GetDlgItem(IDC_BTN_MIN)->MoveWindow(975,0,20,20);
	m_BtnMin.DrawTransparent(TRUE);
	/*m_BtnMin.SetFlat(FALSE);*/
	m_BtnMin.SetBitmaps(IDB_BIT_MIN,RGB(255,255,255));
	m_BtnMin.SetTooltipText(_T("��С��"));
	
	GetDlgItem(IDC_BTN_OFF)->MoveWindow(1000,0,20,20);
	m_BtnOff.DrawTransparent(TRUE);
	m_BtnOff.SetBitmaps(IDB_BIT_OFF,RGB(255,255,255));
	m_BtnOff.SetTooltipText(_T("�ر�"));

	
	

	
	

	/*theApp.m_pRightLoginView->Create(IDD_RIGHT_LOGIN,this);*/

	CRect rc,rc1;
	GetWindowRect(rc);
	rc1=rc;
	rc.left=rc1.Width()/2-150;
	rc.top=rc1.Height()/2-60;
	rc.right=rc1.Width()/2+150;
	rc.bottom=rc1.Height()/2+60;
	

	m_RightLoginView.Create(IDD_RIGHT_LOGIN);
	theApp.m_pRightLoginView=&m_RightLoginView;
	m_RightLoginView.MoveWindow(&rc);
	m_RightLoginView.ShowWindow(SW_SHOW);

	//////////�����ϱ߽�///////////////////////
	m_TopView.Create(IDD_TOP);
	theApp.m_pTopView=&m_TopView;
	m_TopView.MoveWindow(240,0,1023,28);
	m_TopView.ShowWindow(SW_HIDE);

	/////////���������//////////////////////////
	m_LeftPaneView.Create(IDD_LEFT_PANE);
	theApp.m_LeftPaneView=&m_LeftPaneView;
	m_LeftPaneView.MoveWindow(0,0,240,683);
	m_LeftPaneView.ShowWindow(SW_HIDE);

	////////��ӭ����/////////////////////////////
	m_RightWelView.Create(IDD_RIGHT_WEL);
	theApp.m_pRightWelView=&m_RightWelView;
	m_RightWelView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightWelView.ShowWindow(SW_HIDE);
	///////////��ӱ���//////////////////////////
	m_HeadTextView.Create(IDD_HEADTEXT);
	theApp.m_pHeadTextView=&m_HeadTextView;
	m_HeadTextView.MoveWindow(0,20,1200,200);
	m_HeadTextView.ShowWindow(SW_SHOW);

	////////////��������û�����/////////////////
	m_RightAddUserAccView.Create(IDD_RIGHT_ADDUSERACC);
	theApp.m_pRightAddUserAccView=&m_RightAddUserAccView;
	m_RightAddUserAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightAddUserAccView.ShowWindow(SW_HIDE);

	///////////�����޸��û�����//////////////////
	m_RightChgUserAccView.Create(IDD_RIGHT_CHGUSERACC);
	theApp.m_pRightChgUserAccView=&m_RightChgUserAccView;
	m_RightChgUserAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightChgUserAccView.ShowWindow(SW_HIDE);

	///////////�������ҽ���˻�����//////////////
	m_RightAddDocAccView.Create(IDD_RIGHT_ADDDOCACC);
	theApp.m_pRightAddDocAccView=&m_RightAddDocAccView;
	m_RightAddDocAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightAddDocAccView.ShowWindow(SW_HIDE);

	//////////�����鿴ҽ���˻�����///////////////
	m_RightChgDocAccView.Create(IDD_RIGHT_CHGDOCACC);
	theApp.m_pRightChgDocAccView=&m_RightChgDocAccView;
	m_RightChgDocAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightChgDocAccView.ShowWindow(SW_HIDE);

	//////////������ӹ���Ա�˻�����/////////////////////////
	m_RightAddManAccView.Create(IDD_RIGHT_ADDMANACC);
	theApp.m_pRightAddManAccView=&m_RightAddManAccView;
	m_RightAddManAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightAddManAccView.ShowWindow(SW_HIDE);

	/////////////�鿴����Ա�˻�����//////////////////////////
	m_RightChgManAccView.Create(IDD_RIGHT_CHGMANACC);
	theApp.m_pRightChgManAccView=&m_RightChgManAccView;
	m_RightChgManAccView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightChgManAccView.ShowWindow(SW_HIDE);

	////////////����������Ϣ����////////////////////////////
	m_RightMessSendView.Create(IDD_MESS_SEND);
	theApp.m_pRightMessSendView=&m_RightMessSendView;
	m_RightMessSendView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightMessSendView.ShowWindow(SW_HIDE);

	//////////////////////////////////////////////////////
	m_RightMessSendView1.Create(IDD_MESS_SEND1);
	theApp.m_pRightMessSendView1=&m_RightMessSendView1;
	m_RightMessSendView1.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightMessSendView1.ShowWindow(SW_HIDE);

	////////////����������кŽ���/////////////////////////
	m_RightAddSeriView.Create(IDD_RIGHT_ADDSERI);
	theApp.m_pRightAddSeriView=&m_RightAddSeriView;
	m_RightAddSeriView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightAddSeriView.ShowWindow(SW_HIDE);

    /////////////�����鿴���кŽ���///////////////////////
	m_RightChgSeriView.Create(IDD_RIGHT_CHGSERI);
	theApp.m_pRightChgSeriView=&m_RightChgSeriView;
	m_RightChgSeriView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightChgSeriView.ShowWindow(SW_HIDE);

	//////////////������˾ְԱ�����//////////////////////
	m_RightEmployee.Create(IDD_RIGHT_EMPLOYEE);
	theApp.m_pRightEmployee = &m_RightEmployee;
	m_RightEmployee.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightEmployee.ShowWindow(SW_HIDE);

	/////////////����ƽ̨������Ȩ����/////////////////////
	m_RightAuthorizeView.Create(IDD_RIGHT_AUTHORIZE);
	theApp.m_pRightAuthorizeView = &m_RightAuthorizeView;
	m_RightAuthorizeView.MoveWindow(240,28,rc1.right-200,rc1.bottom-100);
	m_RightAuthorizeView.ShowWindow(SW_HIDE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	/*CDC Dc;*/
	// 	CPaintDC dc(this);
	// 	CBitmap bitmap;
	// // 	CRect rect;
	// // 	GetClientRect(&rect);
	// 	bitmap.LoadBitmapW(IDB_BIT_BK);
	// 	/*CBrush brush;*/
	// 	brush.CreatePatternBrush(&bitmap);
	// 	CBrush* pOldBrush=dc.SelectObject(&brush);
	// 	/*dc.SelectObject(&brush);*/
	// 	dc.Rectangle(0,0,683,1024);
	// 	dc.SelectObject(pOldBrush);
	/*ShowHead(FALSE);*/
// 	if(m_RightLoginView.m_HideMode)
// 	{
// 		GetDlgItem(IDC_HEAD)->SetWindowText(_T(""));
// 	    GetDlgItem(IDC_HEAD1)->SetWindowText(_T(""));
// 		m_RightLoginView.m_HideMode=FALSE;
// 	}
// 	CPaintDC dc(this);
// 	CBrush Brush;
// 	Brush.CreateSolidBrush(theApp.m_LeftColr);
// 	CBrush* pOldBrush=dc.SelectObject(&Brush);
// 	dc.FillRect(CRect(0,0,240,24),&Brush);
// 	dc.SelectObject(pOldBrush);

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CMyManageDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd==this)
	{
		return m_Brush;
	}
	return hbr;
}


void CMyManageDlg::OnBnClickedBtnOff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CMyManageDlg::OnBnClickedBtnMin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_MINIMIZE);

}


void CMyManageDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rc;
	GetClientRect(rc);

	rc.bottom = 28;
	if(PtInRect(rc,point))
	{
		m_Point1=point;
		m_MoveMode=TRUE;
	}
		CDialogEx::OnLButtonDown(nFlags, point);
}


void CMyManageDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_MoveMode)
	{
		CRect rt;
		GetWindowRect(rt);
		m_PosOri.x=rt.left;
		m_PosOri.y=rt.top;

		m_Point2=point;
		CPoint Pos2;
		double xDistance;
		double yDistance;
		xDistance=m_Point2.x-m_Point1.x;
		yDistance=m_Point2.y-m_Point1.y;


		Pos2.x=m_PosOri.x+xDistance;
		Pos2.y=m_PosOri.y+yDistance;

		SetWindowPos(NULL,Pos2.x,Pos2.y,0,0,SWP_NOSIZE);
		//m_Point1=m_Point2;


	}
	CDialogEx::OnMouseMove(nFlags, point);
}



void CMyManageDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
// 	CPoint Pos2;
// 	double xDistance;
// 	double yDistance;
// 	xDistance=m_Point2.x-point.x;
// 	yDistance=m_Point2.y-point.y;
// 	Pos2.x=m_PosOri.x+xDistance;
// 	Pos2.y=m_PosOri.y+yDistance;
// 	m_PosOri=Pos2;
	m_MoveMode=FALSE;
	/*SetWindowPos(NULL,Pos2.x,Pos2.y,1023,683,0);*/
	CDialogEx::OnLButtonUp(nFlags, point);
}


//void CMyManageDlg::OnBnClickedBtnLogin()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	/*MessageBox(_T("aaaa"));*/
//}

void CMyManageDlg::ShowView(CDialog* RightView, CDialog* PreView)
{
	RightView->ShowWindow(SW_SHOW);
	PreView->ShowWindow(SW_HIDE);
	PreView=RightView;
}


BOOL CMyManageDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
