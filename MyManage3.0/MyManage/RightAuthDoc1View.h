#pragma once
#include "afxwin.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthDoc1View �Ի���

class CRightAuthDoc1View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthDoc1View)

public:
	CRightAuthDoc1View(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightAuthDoc1View();

// �Ի�������
	enum { IDD = IDD_AUTH_DOC1 };
public:
	CListCtrl m_doclist;
	CListCtrl m_chodoclist;
	int docrow,chodocrow;
	CString docname,doccellnum;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
private:
	CComboBox m_QueType;
	CButtonST m_BtnQue;
	CButtonST m_Btn;
public:
	CButtonST m_DelDoc1;
	CXPGroupBox m_Group;
};
