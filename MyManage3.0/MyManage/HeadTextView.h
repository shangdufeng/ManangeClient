#pragma once


// CHeadTextView �Ի���

class CHeadTextView : public CDialog
{
	DECLARE_DYNAMIC(CHeadTextView)

public:
	CHeadTextView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHeadTextView();

// �Ի�������
	enum { IDD =IDD_HEADTEXT };
private:
	CFont m_head;
	CFont m_head1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
