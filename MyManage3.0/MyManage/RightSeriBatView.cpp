// RightSeriBatView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightSeriBatView.h"
#include "afxdialogex.h"


// CRightSeriBatView �Ի���

IMPLEMENT_DYNAMIC(CRightSeriBatView, CDialog)

CRightSeriBatView::CRightSeriBatView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightSeriBatView::IDD, pParent)
{

}

CRightSeriBatView::~CRightSeriBatView()
{
}

void CRightSeriBatView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SERIBAT, m_seribat);
	DDX_Control(pDX, IDC_READFILE, m_Sel);
	DDX_Control(pDX, IDC_BUTTON1, m_Del);
	DDX_Control(pDX, IDC_SUB, m_Sub);
}


BEGIN_MESSAGE_MAP(CRightSeriBatView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_READFILE, &CRightSeriBatView::OnBnClickedReadfile)
END_MESSAGE_MAP()


// CRightSeriBatView ��Ϣ�������


BOOL CRightSeriBatView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_seribat.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_seribat.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_seribat.InsertColumn(1,_T("���к�"),LVCFMT_CENTER,200);
	m_seribat.InsertColumn(2,_T("�豸����"),LVCFMT_CENTER,100);
	m_seribat.InsertColumn(3,_T("�ϴ���"),LVCFMT_CENTER,100);
	m_seribat.InsertColumn(4,_T("�ϴ�ʱ��"),LVCFMT_CENTER,100);

	m_Sel.DrawTransparent(TRUE);
	m_Sel.SetFlat(FALSE);
	m_Sel.SetTooltipText(_T("ѡ���ļ�"));
	

	m_Del.DrawTransparent(TRUE);
	m_Del.SetFlat(FALSE);
	m_Del.SetTooltipText(_T("ɾ��"));

	m_Sub.DrawTransparent(TRUE);
	m_Sub.SetFlat(FALSE);
	m_Sub.SetTooltipText(_T("�ύ"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightSeriBatView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	CPen   Pen;
	Pen.CreatePen(PS_SOLID,1,theApp.m_LineColor);
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CPen*   pOldPen=dc.SelectObject(&Pen);
	dc.Rectangle(CRect(0,0,720,530));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}


HBRUSH CRightSeriBatView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd->GetDlgCtrlID()==IDC_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightSeriBatView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_READFILE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightSeriBatView::OnBnClickedReadfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrTitle=_T("ѡ���ļ�");
	FileDlg.m_ofn.lpstrFilter=_T("Ecxel File(*.xlsx;*.xls)|*.xls;*.xlsx");
	if(FileDlg.DoModal()==IDOK)
	{
		m_DocFile=FileDlg.GetPathName();
		ExcelToList(m_DocFile,m_seribat);
		UpdateData(FALSE);
	}
}

void CRightSeriBatView::ExcelToList(CString m_FilePath, CListCtrl& m_List)
{
	//��ɾ���б�����//
	m_List.DeleteAllItems();
	while(m_List.GetHeaderCtrl()->GetItemCount()>0)
	{
		m_List.DeleteColumn(0);
	}
	// 	int colnum=m_List.GetHeaderCtrl()->GetItemCount();
	// 	for (int i=0; i<colnum;i++)
	// 	{
	// 		m_List.DeleteColumn(i);
	// 	}
	//����
	CApplication app;
	CWorkbook book;
	CWorkbooks books;
	CWorksheet sheet;
	CWorksheets sheets;
	CRange range;
	LPDISPATCH lpDisp;
	//�������//
	COleVariant covOptional((long)
		DISP_E_PARAMNOTFOUND,VT_ERROR);
	if (!app.CreateDispatch(_T("Excel.Application")))
	{
		this->MessageBox(_T("�޷�����ExcelӦ��"));
		return;
	}
	books = app.get_Workbooks();
	//��Excel������m_FilePathΪExcel���·����//
	lpDisp = books.Open(m_FilePath,covOptional
		,covOptional,covOptional,covOptional
		,covOptional,covOptional,covOptional
		,covOptional,covOptional,covOptional
		,covOptional,covOptional,covOptional
		,covOptional);
	book.AttachDispatch(lpDisp);
	sheets = book.get_Worksheets();
	sheet = sheets.get_Item(COleVariant((short)1));
	CStringArray m_HeadName;
	//vector<CString> m_HeadName;
	for (int i=1;i<26;i++)
	{
		CString m_pos = GetEnglishCharacter(i);
		m_pos = m_pos + _T("1");
		range = sheet.get_Range(COleVariant(m_pos),COleVariant(m_pos));
		//��õ�Ԫ�������
		COleVariant rValue;
		rValue = COleVariant(range.get_Value2());
		//ת���ɿ��ַ�//
		rValue.ChangeType(VT_BSTR);
		//ת����ʽ�������//
		CString m_content = CString(rValue.bstrVal);
		if (m_content!=_T(""))
		{
			m_HeadName.Add(m_content);
		}
	}
	InitList(m_List,m_HeadName);	
	CStringArray m_ContentArr;
	for (int ItemNum = 0;ItemNum<10000;ItemNum++)
	{
		for (int j=1;j<m_List.GetHeaderCtrl()->GetItemCount();j++)
		{
			CString m_pos = GetEnglishCharacter(j);
			CString m_Itempos;
			m_Itempos.Format(_T("%d"),ItemNum+2);
			CString m_str = m_pos+m_Itempos;
			range = sheet.get_Range(COleVariant(m_str),COleVariant(m_str));
			//��õ�Ԫ�������
			COleVariant rValue;
			rValue = COleVariant(range.get_Value2());
			//ת���ɿ��ַ�//
			rValue.ChangeType(VT_BSTR);
			//ת����ʽ�������//
			CString m_content = CString(rValue.bstrVal);
			m_ContentArr.Add(m_content);
		}
		if (m_ContentArr.GetAt(0)!=_T(""))
			/*if(m_ContentArr.GetSize()<=0&&m_ContentArr.GetSize()<=2)*/
		{
			InsertList(m_List,m_ContentArr);
			m_ContentArr.RemoveAll();
		}
		else{
			break;
		}
	}



	book.put_Saved(TRUE);
	app.Quit();
	range.ReleaseDispatch();  
	sheet.ReleaseDispatch();  
	sheets.ReleaseDispatch();  
	book.ReleaseDispatch();  
	books.ReleaseDispatch();  
	app.ReleaseDispatch();
}

CString CRightSeriBatView::GetEnglishCharacter(int Num)
{
	CString str2;
	switch(Num){
	case 1:
		str2.Format(_T("A"));
		break;
	case 2:
		str2.Format(_T("B"));
		break;
	case 3:
		str2.Format(_T("C"));
		break;
	case 4:
		str2.Format(_T("D"));
		break;
	case 5:
		str2.Format(_T("E"));
		break;
	case 6:
		str2.Format(_T("F"));
		break;
	case 7:
		str2.Format(_T("G"));
		break;
	case 8:
		str2.Format(_T("H"));
		break;
	case 9:
		str2.Format(_T("I"));
		break;
	case 10:
		str2.Format(_T("J"));
		break;
	case 11:
		str2.Format(_T("K"));
		break;
	case 12:
		str2.Format(_T("L"));
		break;
	case 13:
		str2.Format(_T("M"));
		break;
	case 14:
		str2.Format(_T("N"));
		break;
	case 15:
		str2.Format(_T("O"));
		break;
	case 16:
		str2.Format(_T("P"));
		break;
	case 17:
		str2.Format(_T("Q"));
		break;
	case 18:
		str2.Format(_T("R"));
		break;
	case 19:
		str2.Format(_T("S"));
		break;
	case 20:
		str2.Format(_T("T"));
		break;
	case 21:
		str2.Format(_T("U"));
		break;
	case 22:
		str2.Format(_T("V"));
		break;
	case 23:
		str2.Format(_T("W"));
		break;
	case 24:
		str2.Format(_T("X"));
		break;
	case 25:
		str2.Format(_T("Y"));
		break;
	case 26:
		str2.Format(_T("Z"));
		break;
	default:
		str2.Format(_T("Z"));
		break;
	}
	return str2;
}

void CRightSeriBatView::InitList(CListCtrl& m_List, CStringArray& ColumName)
{
	LONG lStyle; 
	lStyle = GetWindowLong(m_List.m_hWnd, GWL_STYLE); 
	lStyle &= ~LVS_TYPEMASK;
	lStyle |= LVS_REPORT; 
	SetWindowLong(m_List.m_hWnd, GWL_STYLE, lStyle);
	DWORD dwStyle = m_List.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	dwStyle |= LVS_EX_CHECKBOXES;
	m_List.SetExtendedStyle(dwStyle); 

	m_List.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);

	/*CString str=ColumName.GetAt(0);*/

	if(ColumName.GetSize()<=0/*||ColumName.GetSize()>2*/)
	{
		MessageBox(_T("������д��ʽ�Ƿ���ȷ��"));
		return;
	}

	else
	{
		m_List.InsertColumn(1,ColumName.GetAt(0),LVCFMT_CENTER,200);
		m_List.InsertColumn(2,ColumName.GetAt(1),LVCFMT_CENTER,100);
		m_List.InsertColumn(3,_T("�ϴ���"),LVCFMT_CENTER,100);
		m_List.InsertColumn(4,_T("�ϴ�ʱ��"),LVCFMT_CENTER,100);
	}



	// 	for (int i=0;i<ColumName.GetSize();i++)
	// 	{
	// 		m_List.InsertColumn(i,ColumName.GetAt(i),LVCFMT_LEFT,100);
	// 	}
}

void CRightSeriBatView::InsertList(CListCtrl& m_List, CStringArray& ItemArr)
{
	int ArrNum = ItemArr.GetSize();
	if (ArrNum < m_List.GetHeaderCtrl()->GetItemCount()-1)
	{
		return;
	}
	int nCount=m_List.GetHeaderCtrl()->GetItemCount()-1;
	int pos = m_List.GetItemCount();
	CString num;
	num.Format(_T("%d"),pos+1);
	m_List.InsertItem(pos,num);
	m_List.SetItemText(pos,0,num);
	for (int colum=0;colum<m_List.GetHeaderCtrl()->GetItemCount()-1;colum++)
	{
		m_List.SetItemText(pos,colum+1,ItemArr.GetAt(colum));
	}
}