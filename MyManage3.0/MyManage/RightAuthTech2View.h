#pragma once
#include "afxwin.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthTech2View �Ի���

class CRightAuthTech2View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthTech2View)

public:
	CRightAuthTech2View(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightAuthTech2View();

// �Ի�������
	enum { IDD = IDD_AUTH_TECH2 };
public:
	CListCtrl m_tplist;
	CListCtrl m_chotplist;
	int tprow,chotprow;
	CString tpname,tpcellnum;
	CString m_quetechtype;
	CString m_quetechtext;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CComboBox m_QueType;
	CButtonST m_BtnQue;
public:
	CButtonST m_AddTech;
private:
	CButtonST m_DelTech;
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
