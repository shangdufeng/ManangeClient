#pragma once
#include "afxwin.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightChgManAccView �Ի���

class CRightChgManAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgManAccView)

public:
	CRightChgManAccView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightChgManAccView();

// �Ի�������
	enum { IDD = IDD_RIGHT_CHGMANACC };
public:
	CString m_quetype;
	CString m_quetext;
	CString manduty;
	CListCtrl m_manlist;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CComboBox m_QueType;
	CButtonST m_BtnQue;
public:
	CButtonST m_BtnOK;
	CButtonST m_BtnSub;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
};
