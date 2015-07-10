#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CRightEmployee �Ի���

class CRightEmployee : public CDialog
{
	DECLARE_DYNAMIC(CRightEmployee)

public:
	CRightEmployee(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightEmployee();

// �Ի�������
	enum { IDD = IDD_RIGHT_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListCtrl m_EmployeeList;
	virtual BOOL OnInitDialog();
	CComboBox m_QueType;
	CDateTimeCtrl m_StartTime;
	CDateTimeCtrl m_EndTime;
	afx_msg void OnBnClickedBtnQue();
	afx_msg LRESULT OnSmQueEmployee(WPARAM wParam,LPARAM lParam);
};
