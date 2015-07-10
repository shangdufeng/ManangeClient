// LeftPaneView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "LeftPaneView.h"
#include "afxdialogex.h"


// CLeftPaneView �Ի���

IMPLEMENT_DYNAMIC(CLeftPaneView, CDialog)

CLeftPaneView::CLeftPaneView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftPaneView::IDD, pParent)
{
	m_Brush.CreateSolidBrush(theApp.m_LeftColr);
	m_myFont.CreatePointFont(100,_T("����")); 
}

CLeftPaneView::~CLeftPaneView()
{
}

void CLeftPaneView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIRECTREE, m_tree);
	DDX_Control(pDX, IDC_TREE_CS2, m_TreeCS2);
	DDX_Control(pDX, IDC_TREE_CS1, m_TreeCS1);
	DDX_Control(pDX, IDC_TREE_MAN, m_TreeMan);
}


BEGIN_MESSAGE_MAP(CLeftPaneView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(TVN_SELCHANGED, IDC_DIRECTREE, &CLeftPaneView::OnTvnSelchangedDirectree)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_NOTIFY(TVN_SELCHANGING, IDC_DIRECTREE, &CLeftPaneView::OnTvnSelchangingDirectree)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CS1, &CLeftPaneView::OnTvnSelchangedTreeCs1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CS2, &CLeftPaneView::OnTvnSelchangedTreeCs2)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MAN, &CLeftPaneView::OnTvnSelchangedTreeMan)
END_MESSAGE_MAP()


// CLeftPaneView ��Ϣ�������


BOOL CLeftPaneView::OnInitDialog()
{
	CDialog::OnInitDialog();



	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tree.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeCS1.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeCS2.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeMan.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);

	m_tree.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeCS1.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeCS2.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeMan.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);

	hItem1 = m_tree.InsertItem(_T("�˻�����"),TVI_ROOT);

	hItem11 = m_tree.InsertItem(_T("�û��˻�����"),hItem1);
	hItem111=m_tree.InsertItem(_T("����û��˻�"),hItem11);
	hItem112=m_tree.InsertItem(_T("�鿴�û��˻�"),hItem11,hItem111 );

	hItem12 = m_tree.InsertItem(_T("ҽ���˻�����"),hItem1,hItem11);
	hItem121=m_tree.InsertItem(_T("���ҽ���˻�"),hItem12);
	hItem122=m_tree.InsertItem(_T("�鿴ҽ���˻�"),hItem12,hItem121 );

	hItem13 = m_tree.InsertItem(_T("����Ա�˻�����"),hItem1,hItem12);
	hItem131=m_tree.InsertItem(_T("��ӹ���Ա�˻�"),hItem13);
	hItem132=m_tree.InsertItem(_T("�鿴����Ա�˻�"),hItem13,hItem131 );
	hItem133=m_tree.InsertItem(_T("�鿴��˾ְԱ"),hItem13,hItem133);

	hItem2 = m_tree.InsertItem(_T("���кŹ���"),TVI_ROOT,hItem1);
	hItem21 = m_tree.InsertItem(_T("������к�"),hItem2);
	hItem22 = m_tree.InsertItem(_T("�鿴���к�"),hItem2,hItem21);

	hItem3 = m_tree.InsertItem(_T("������Ϣ"),TVI_ROOT,hItem1);

	hItem4 = m_tree.InsertItem(_T("����ƽ̨"),TVI_ROOT,hItem1);
	hItem41 = m_tree.InsertItem(_T("��¼"),hItem4);
	hItem42 = m_tree.InsertItem(_T("��ӭ"),hItem4,hItem41);
	m_tree.InsertItem(_T("�˳�"),hItem4,hItem42);
	m_tree.SetBkColor(theApp.m_LeftColr);
	m_TreeCS1.SetBkColor(theApp.m_LeftColr);
	m_TreeCS2.SetBkColor(theApp.m_LeftColr);
	m_TreeMan.SetBkColor(theApp.m_LeftColr);

	//***********************�ͷ�����**********************************
	CS1Item1 = m_TreeCS1.InsertItem(_T("�˻�����"),TVI_ROOT);
	CS1Item11 = m_TreeCS1.InsertItem(_T("��Ӽ���Ȩ�˻�"),CS1Item1);
	CS1Item12 = m_TreeCS1.InsertItem(_T("�鿴�ͷ������˻�"),CS1Item1,CS1Item11);

	CS1Item2 = m_TreeCS1.InsertItem(_T("����ƽ̨"),TVI_ROOT,CS1Item1);
	CS1Item21 = m_TreeCS1.InsertItem(_T("��ӭ"),CS1Item2);
	CS1Item22 = m_TreeCS1.InsertItem(_T("��¼"),CS1Item2,CS1Item21);

	m_TreeCS1.InsertItem(_T("�˳�"),CS1Item2,CS1Item22);

	CS1Item3 = m_TreeCS1.InsertItem(_T("������Ϣ"),TVI_ROOT,CS1Item2);

	CS1Item4 = m_TreeCS1.InsertItem(_T("���кŹ���"),TVI_ROOT,CS1Item3);
	CS1Item41 = m_TreeCS1.InsertItem(_T("������к�"),CS1Item4);
	CS1Item42 = m_TreeCS1.InsertItem(_T("�鿴���к�"),CS1Item4,CS1Item41);

	//**************************�ͷ�����******************************
	CS2Item1 = m_TreeCS2.InsertItem(_T("�˻�����"),TVI_ROOT);
	CS2Item11= m_TreeCS2.InsertItem(_T("�û��˻�����"),CS2Item1);
	CS2Item111 = m_TreeCS2.InsertItem(_T("����û��˻�"),CS2Item11);
	CS2Item112 = m_TreeCS2.InsertItem(_T("�鿴�û��˻�"),CS2Item11,CS2Item111);
	CS2Item12 = m_TreeCS2.InsertItem(_T("ҽ���˻�����"),CS2Item1,CS2Item11);
	CS2Item121 = m_TreeCS2.InsertItem(_T("���ҽ���˻�"),CS2Item12);
	CS2Item122 = m_TreeCS2.InsertItem(_T("�鿴ҽ���˻�"),CS2Item12,CS2Item121);

	CS2Item2 = m_TreeCS2.InsertItem(_T("����ƽ̨"),TVI_ROOT,CS2Item1);
	CS2Item21 = m_TreeCS2.InsertItem(_T("��¼"),CS2Item2);
	CS2Item22 = m_TreeCS2.InsertItem(_T("��ӭ"),CS2Item2,CS2Item21);

	m_TreeCS2.InsertItem(_T("�˳�"),CS2Item2,CS2Item22);

	CS2Item3 = m_TreeCS2.InsertItem(_T("������Ϣ"),TVI_ROOT,CS2Item2);
	CS2Item4 = m_TreeCS2.InsertItem(_T("�鿴���к�"),TVI_ROOT,CS2Item3);

	//****************************ƽ̨����*****************************
	MANItem1 = m_TreeMan.InsertItem(_T("�˻�����"),TVI_ROOT);
	MANItem11 = m_TreeMan.InsertItem(_T("��Ȩ"),MANItem1);
    MANItem12 = m_TreeMan.InsertItem(_T("�鿴��˾ְԱ"),MANItem1,MANItem11);

	MANItem2 = m_TreeMan.InsertItem(_T("����ƽ̨"),TVI_ROOT,MANItem1);
	MANItem21 = m_TreeMan.InsertItem(_T("��¼"),MANItem2);
	MANItem22 = m_TreeMan.InsertItem(_T("��ӭ"),MANItem2,MANItem21);
    m_TreeMan.InsertItem(_T("�˳�"),MANItem2,MANItem22);

	MANItem3 = m_TreeMan.InsertItem(_T("������Ϣ"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CLeftPaneView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
// 	CBitmap   bitmap;
// 	bitmap.LoadBitmap(IDB_BIT_LEFT); 
// 	CBrush   brush;
// 	brush.CreatePatternBrush(&bitmap);
// 	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
// 	/*dc.Rectangle(CRect(0,0,240,683));  */
// 	dc.FillRect(CRect(0,0,240,683),&brush);
// 	dc.SelectObject(pOldBrush);
}


HBRUSH CLeftPaneView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
//  	if (pWnd->GetDlgCtrlID()==IDC_DIRECTREE) 
//  	{ 
// 		pDC->SelectObject(&m_myFont);
//  		pDC->SetBkMode(TRANSPARENT);
//  		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
// 	}
	return m_Brush;
	/*return hbr;*/
}


void CLeftPaneView::OnTvnSelchangedDirectree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItem=m_tree.GetSelectedItem();
	CString s=m_tree.GetItemText(hItem);
	if(s==_T("����û��˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("�鿴�û��˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("���ҽ���˻�"))
	{
		theApp.m_pRightAddDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("�鿴ҽ���˻�"))
	{
		theApp.m_pRightChgDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("��ӹ���Ա�˻�"))
	{
		theApp.m_pRightAddManAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("�鿴����Ա�˻�"))
	{
		theApp.m_pRightChgManAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("�鿴��˾ְԱ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);

		theApp.m_pRightEmployee->ShowWindow(SW_SHOW);
	}
	if (s==_T("��¼"))
	{
	
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(s==_T("��ӭ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);

	}
	if(s==_T("�˳�"))
	{
		exit(0);
	}
	if(s==_T("������Ϣ"))
	{
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_SHOW);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("������к�"))
	{
		theApp.m_pRightAddSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("�鿴���к�"))
	{
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rc(0,0,240,28);
	if(PtInRect(rc,point))
	{
		theApp.m_MyManageDlg->m_Point1=point;
		theApp.m_MyManageDlg->m_MoveMode=TRUE;
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}



void CLeftPaneView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	theApp.m_MyManageDlg->m_MoveMode=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}


void CLeftPaneView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	theApp.m_MyManageDlg->OnMouseMove(nFlags,point);
	CDialog::OnMouseMove(nFlags, point);
}


void CLeftPaneView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nChar==0x0d)
	{
	/*	theApp.m_EnterkeyMode=TRUE;*/
	}
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CLeftPaneView::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	return;
/*	CDialog::OnOK();*/
}


BOOL CLeftPaneView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLeftPaneView::OnTvnSelchangingDirectree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
/*	if()*/
	NM_TREEVIEW* pTreeView=(NM_TREEVIEW*)pNMTreeView; 
// 	if (theApp.m_AuthLimit==0)
// 	{
// 		if((pTreeView->itemNew.hItem==hItem111)||
// 			(pTreeView->itemNew.hItem==hItem112)||
// 			(pTreeView->itemNew.hItem==hItem121)||
// 			(pTreeView->itemNew.hItem==hItem122)||
// 			(pTreeView->itemNew.hItem==hItem131)||
// 			(pTreeView->itemNew.hItem==hItem132)||
// 			(pTreeView->itemNew.hItem==hItem3)||
// 			(pTreeView->itemNew.hItem==hItem21)||
// 			(pTreeView->itemNew.hItem==hItem22)||
// 			(pTreeView->itemNew.hItem==hItem42))
// 		{
// 			MessageBox(_T("���޴�Ȩ��"));
// 			*pResult = 1;
// 			return;
// 		}
// 	}
// 	else if (theApp.m_AuthLimit==1)
// 	{
// 		*pResult = 0;
// 	}
// 	else if (theApp.m_AuthLimit==2)
// 	{
// 		if((pTreeView->itemNew.hItem==hItem13)||
// 			(pTreeView->itemNew.hItem==hItem131)||
// 			(pTreeView->itemNew.hItem==hItem132)||
// 			(pTreeView->itemNew.hItem==hItem2)||
// 			(pTreeView->itemNew.hItem==hItem21)||
// 			(pTreeView->itemNew.hItem==hItem22))
// 		{
// 			MessageBox(_T("���޴�Ȩ��"));
// 			*pResult = 1;
// 			return;
// 		}
// 	}

	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeCs1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//*****************�ͷ�����****************************
	HTREEITEM hItemCS1=m_TreeCS1.GetSelectedItem();
	CString CS1=m_TreeCS1.GetItemText(hItemCS1);
	if(CS1==_T("��Ӽ���Ȩ�˻�"))
	{

	}
	if(CS1==_T("�鿴�ͷ������˻�"))
	{

	}
	if(CS1==_T("��ӭ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("��¼"))
	{
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(CS1==_T("�˳�"))
	{
		if(AfxMessageBox(_T("�Ƿ��˳���"),MB_OKCANCEL)==IDOK)
		{
			exit(0);
		}
	}
	if(CS1==_T("������к�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("�鿴���к�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("������Ϣ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeCs2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItemCS2=m_TreeCS2.GetSelectedItem();
	CString CS2=m_TreeCS2.GetItemText(hItemCS2);
	if(CS2==_T("����û��˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("�鿴�û��˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("���ҽ���˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("�鿴ҽ���˻�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if (CS2==_T("��¼"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(CS2==_T("��ӭ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("�˳�"))
	{
		if(AfxMessageBox(_T("�Ƿ��˳���"),MB_OKCANCEL)==IDOK)
			exit(0);
	}
	if(CS2==_T("������Ϣ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("�鿴���к�"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeMan(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItemMAN=m_TreeMan.GetSelectedItem();
	CString MAN=m_TreeCS2.GetItemText(hItemMAN);
	if(MAN==_T("��Ȩ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_SHOW);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("�鿴��˾ְԱ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_SHOW);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("��¼"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(MAN==_T("�˳�"))
	{
		if(AfxMessageBox(_T("�Ƿ��˳���"),MB_OKCANCEL)==IDOK)
			exit(0);
	}
	if(MAN==_T("������Ϣ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("��ӭ"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}
