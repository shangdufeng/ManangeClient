#pragma once
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
/*#include "MyManageDlg.h"*/


// CRightLoginView �Ի���

class CRightLoginView : public CDialog
{
	DECLARE_DYNAMIC(CRightLoginView)

public:
	CRightLoginView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightLoginView();

// �Ի�������
	enum { IDD = IDD_RIGHT_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Btn;
	/*CMyManageDlg m_MyManageDlg;*/

public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	
	afx_msg void OnBnClickedBtnLogin();
	afx_msg LRESULT OnSmLoginEx(WPARAM wParam,LPARAM lParam);
//	BOOL m_HideMode;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
