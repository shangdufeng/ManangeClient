#pragma once
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightChgSeriView �Ի���

class CRightChgSeriView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgSeriView)

public:
	CRightChgSeriView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightChgSeriView();

// �Ի�������
	enum { IDD = IDD_RIGHT_CHGSERI };
public:
		CString m_seriID;
		CListCtrl m_userinfo;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Btn;
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
