#pragma once


// CRightQueExecpView �Ի���

class CRightQueExecpView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueExecpView)

public:
	CRightQueExecpView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightQueExecpView();

// �Ի�������
	enum { IDD = IDD_RIGHT_QUEEXCEP };
public:
	CListCtrl m_excepinfo;
	CDateTimeCtrl m_start;
	CDateTimeCtrl end;
	CButtonST m_Btn;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
