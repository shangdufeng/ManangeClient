#pragma once


// CRightDocDiagView �Ի���

class CRightDocDiagView : public CDialog
{
	DECLARE_DYNAMIC(CRightDocDiagView)

public:
	CRightDocDiagView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightDocDiagView();

// �Ի�������
	enum { IDD = IDD_DOC_DIAG };
public:
	CListCtrl m_diag;
	CDateTimeCtrl m_enddate;
	CDateTimeCtrl m_startdate;
	CString m_quetype;
	CString m_quetext;
	CButtonST m_Btn;
	CButtonST m_Btn1;
	CButtonST m_Btn2;
	CComboBox m_Mem;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
