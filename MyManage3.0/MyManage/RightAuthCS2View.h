#pragma once
#include "afxwin.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthCS2View �Ի���

class CRightAuthCS2View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthCS2View)

public:
	CRightAuthCS2View(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightAuthCS2View();

// �Ի�������
	enum { IDD = IDD_AUTH_CS2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_userlist;
	CListCtrl m_chouserlist;
	CListCtrl m_doclist;
	CListCtrl m_chodoclist;
	CListCtrl m_csrlist;
	CString username,usercellnum,docname,doccellnum;
	int userrow,chouserrow,docrow,chodocrow;
	int chouserlistrow,chodoclistrow;
	CString csrname,csrcellnum;
	int csrrow,chocsrrow;
	CString m_usertype;
	CString m_usertext;
	CString m_doctype;
	CString m_doctext;
	CListCtrl m_chocsrlist;
	CString m_quecsrtype;
	CString m_quecsrtext;
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
private:
	CComboBox m_QueTypeUser;
	CComboBox m_QueTypeDoc;
	CComboBox m_QueTypeMan;
public:
	CButtonST m_BtnQueUser;
	CButtonST m_AddUser;
private:
	CButtonST m_DelUser;
public:
	CButtonST m_BtnQueDoc;
	CButtonST m_AddDoc;
	CButtonST m_DelDoc;
	CButtonST m_BtnQueMan;
	CButtonST m_AddMan;
	CButtonST m_DelMan;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
	CXPGroupBox m_Group2;
};
