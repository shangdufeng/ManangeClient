// RightQueBasView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueBasView.h"
#include "afxdialogex.h"


// CRightQueBasView �Ի���

IMPLEMENT_DYNAMIC(CRightQueBasView, CDialog)

CRightQueBasView::CRightQueBasView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueBasView::IDD, pParent)
{

}

CRightQueBasView::~CRightQueBasView()
{
}

void CRightQueBasView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_CELLNUMBER, m_cell);
	DDX_Text(pDX, IDC_BIRTH, m_birth);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	//  DDX_Text(pDX, IDC_IDNUMBER, m_ID);
	DDX_CBString(pDX, IDC_GENDER, m_gender);
	DDX_CBString(pDX, IDC_USERTYPE, m_usertype);
	DDX_Text(pDX, IDC_SERIALNUM, m_seri);
	DDX_Text(pDX, IDC_JOB, m_job);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_CBString(pDX, IDC_BLOODTYPE, m_bloodtype);
	DDX_Text(pDX, IDC_PAIRDOC, m_pairdoc);
	DDX_Text(pDX, IDC_EMERCONT, m_emercont);
	DDX_Text(pDX, IDC_CONTACTNUM, m_emercontnum);
	DDX_Text(pDX, IDC_SURGERY, m_sur);
	DDX_Text(pDX, IDC_DRUG, m_drug);
	DDX_Text(pDX, IDC_DISEASE, m_dis);
	DDX_CBString(pDX, IDC_SMOKE, m_smoke);
	DDX_Text(pDX, IDC_FAMILY, m_family);
	DDX_CBString(pDX, IDC_DRINGK, m_drink);
	DDX_Control(pDX, IDC_USERTYPE, m_usertype1);
	DDX_Control(pDX, IDC_GENDER, m_Gender);
	DDX_Control(pDX, IDC_BLOODTYPE, m_BloodType);
	DDX_Control(pDX, IDC_SMOKE, m_SmoHistory);
	DDX_Control(pDX, IDC_DRINGK, m_DrinkHistory);
	DDX_Control(pDX, IDC_SUB, m_Btn);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
}


BEGIN_MESSAGE_MAP(CRightQueBasView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_SUB, &CRightQueBasView::OnBnClickedSub)
END_MESSAGE_MAP()


// CRightQueBasView ��Ϣ�������


void CRightQueBasView::OnPaint()
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
	dc.Rectangle(CRect(0,0,726,445));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}


HBRUSH CRightQueBasView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightQueBasView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_usertype1.SetCurSel(0);
	m_Gender.SetCurSel(0);
	m_BloodType.SetCurSel(0);
	m_DrinkHistory.SetCurSel(0);
	m_SmoHistory.SetCurSel(0);

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("����ύ��"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightQueBasView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightQueBasView::OnBnClickedSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	User_BaseInfo userbaseinfoup;
	userbaseinfoup.cellnumber=m_cell;
	userbaseinfoup.username=m_name;
	userbaseinfoup.gender=m_gender;
	userbaseinfoup.job=m_job;
	userbaseinfoup.bloodtype=m_bloodtype;
	//userbaseinfoup.IDcardnum=m_ID;
	userbaseinfoup.homeaddress=m_address;
	userbaseinfoup.emercontactor=m_emercont;
	userbaseinfoup.emercontactornum=m_emercontnum;
	userbaseinfoup.surgeryhistory=m_sur;
	userbaseinfoup.diseaseshistory=m_dis;
	userbaseinfoup.familyhistory=m_family;
	userbaseinfoup.drughistory=m_drug;
	userbaseinfoup.smokehistory=m_smoke;
	userbaseinfoup.drinkhistory=m_drink;

	userbaseinfoup.birth=m_birth;
	userbaseinfoup.password=m_password;

	int index;
	CString usertype;
	index=m_usertype1.GetCurSel();
	usertype.Format(_T("%d"),index);

    //theApp.socketmanage.ManChgUserBasInfo(theApp.m_prightchguseraccview->sel_user, userbaseinfoup, usertype);
}
