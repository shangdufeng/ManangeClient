#pragma once
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"


// CRightSeriManView �Ի���

class CRightSeriManView : public CDialog
{
	DECLARE_DYNAMIC(CRightSeriManView)

public:
	CRightSeriManView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightSeriManView();

// �Ի�������
	enum { IDD = IDD_SERI_MAN };
public:
	CListCtrl m_seriman;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Add;
	CButtonST m_Del;
public:
	CButtonST m_Sub;
};
