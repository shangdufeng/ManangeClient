#pragma once


// CRightAuthorizeView �Ի���

class CRightAuthorizeView : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthorizeView)

public:
	CRightAuthorizeView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightAuthorizeView();

// �Ի�������
	enum { IDD = IDD_RIGHT_AUTHORIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
