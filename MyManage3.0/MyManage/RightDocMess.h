#pragma once


// CRightDocMess �Ի���

class CRightDocMess : public CDialog
{
	DECLARE_DYNAMIC(CRightDocMess)

public:
	CRightDocMess(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightDocMess();

// �Ի�������
	enum { IDD = IDD_DOC_MESS };
public:
	CListCtrl m_docmess;
	CDateTimeCtrl m_startdate;
	CDateTimeCtrl m_enddate;
	CButtonST m_Btn;
	CButtonST m_Btn1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
