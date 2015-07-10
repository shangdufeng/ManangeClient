#pragma once
#include "RightDocBasView.h"
#include "RightDocDiagView.h"
#include "RightDocMess.h"
#include "xpgroupbox.h"

// CRightChgDocAccView �Ի���

class CRightChgDocAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgDocAccView)

public:
	CRightChgDocAccView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightChgDocAccView();

// �Ի�������
	enum { IDD = IDD_RIGHT_CHGDOCACC };
public:
	CListCtrl m_docinfo;
	CString m_quetype;
	CString m_quetext;
	CString sel_doc;
	CButtonST m_Btn1;
	CButtonST m_Btn2;
	CButtonST m_Btn;
	CButtonST m_Btn4;
	CComboBox m_QueType;
/*private:*/
	CRightDocBasView     m_RightDocBasView;
	CRightDocDiagView    m_RightDocDiagView;
	CRightDocMess        m_RightDocMessView;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnInfo();
	afx_msg void OnBnClickedBtnRec();
	afx_msg void OnBnClickedBtnMess();
	CXPGroupBox m_Group;
};
