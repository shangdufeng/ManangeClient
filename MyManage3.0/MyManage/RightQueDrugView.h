#pragma once


// CRightQueDrugView �Ի���

class CRightQueDrugView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueDrugView)

public:
	CRightQueDrugView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightQueDrugView();

// �Ի�������
	enum { IDD = IDD_RIGHT_QUEDRUG };
public:
	CListCtrl m_druguseinfo;
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	CButtonST m_Btn;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
