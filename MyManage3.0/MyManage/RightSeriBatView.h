#pragma once
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "d:\��������Ŀ\cbtnst_source\btnst.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CApplication.h"

// CRightSeriBatView �Ի���

class CRightSeriBatView : public CDialog
{
	DECLARE_DYNAMIC(CRightSeriBatView)

public:
	CRightSeriBatView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightSeriBatView();

// �Ի�������
	enum { IDD = IDD_SERI_BAT };
public:
	CListCtrl m_seribat;
	CString m_DocFile;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void ExcelToList(CString m_FilePath,CListCtrl& m_List);
	CString GetEnglishCharacter(int Num);
	void InitList(CListCtrl& m_List,CStringArray& CloumName);
	void InsertList(CListCtrl& m_List,CStringArray& ItemArr);
private:
	CButtonST m_Sel;
	CButtonST m_Del;
	CButtonST m_Sub;


public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedReadfile();
};
