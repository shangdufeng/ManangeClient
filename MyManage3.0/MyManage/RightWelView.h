#pragma once


// CRightWelView �Ի���

class CRightWelView : public CDialog
{
	DECLARE_DYNAMIC(CRightWelView)

public:
	CRightWelView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightWelView();

// �Ի�������
	enum { IDD = IDD_RIGHT_WEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CBrush m_Brush;
	CFont  m_WelFont;
	CFont  m_HintFont;
	CFont  m_MsgFont;
};
