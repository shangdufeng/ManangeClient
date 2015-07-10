
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once
#include <vector>

using std::vector;

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


struct User_BaseInfo 
{
	CString cellnumber; 	//�ֻ���0
	CString password;		//����1
	CString username; 		//�û�����2
	CString gender;			//�Ա�3
	CString birth; 			//����4
	CString job;			//ְҵ5
	CString bloodtype;		//Ѫ��6
	CString homeaddress;	//��ͥסַ7
	CString regionCode;		//�������(��ʱ��û����)8
	CString emercontactor;	//������ϵ��9
	CString emercontactornum;//������ϵ�˺���10
	CString surgeryhistory;	//����ʷ11
	CString diseaseshistory;//����ʷ12
	CString familyhistory;	//����ʷ13
	CString drughistory;	//��ҩʷ14
	CString smokehistory;	//����ʷ15
	CString drinkhistory;	//����ʷ16
};

enum{cmdUserDrugRead,cmdUserDrugUpdate,cmdUserBaseInfoRead,cmdUserBaseInfoInput,cmdUserDoctorInfo,cmdUserDoctorChoose,
	cmdUserDocInfo,cmdUserHealInfoInput,cmdUserLogOn,cmdUserPlatInfoRead,cmdUserRegVery,cmdUserRegVery1,cmdUserReg,cmdUserReg1,
	cmdUserVeriCodeSend,cmdUserVeriCodeSubmit,cmdUserPWResetCode,cmdUserWel,cmdUserLatestHealRead,cmdUserHisHealRead,cmdUserRepRead,
	cmdUserExcepRead,cmdUserSendCode,cmdUserSubCode,cmdUserNewPass,cmdUserMessRead,cmdUserMessSend,cmdUserUploadFile,//�û��˷���
	cmdManAddUser,cmdManQueUser,cmdManChgUserBasInfo,cmdManQueUserDrug,cmdManChgUserDrug,
	cmdManQueUserExcep,cmdManQueUserMess,cmdManQueUserRep,cmdManQueUserUpload,cmdManAddDoc,cmdManQueDoc,
	cmdManChgDocBasInfo,cmdManQueDocRep,cmdManQueDocMess,cmdManQueUser1,cmdManQueDoc1,cmdManQueCSM,cmdManAddManSR,
	cmdManQueCSR,cmdManAddManSM,cmdManQueTM,cmdManAddManTP,cmdManQueTP,cmdManAddManTM,cmdManQueDM,cmdManAddManDP,
	cmdManQueDP,cmdManAddManDM,cmdManQueMan,cmdManQue,cmdManSendMess,cmdManSendMessOT,cmdManAddSeriManu,cmdManAddSeriBat,
	cmdManQueSeri,cmdManLogin//����˽ӿ�

} cmdClient;

enum{
	cmdServerError=-1,/*cmdServerDrugRead=0x0400*/cmdServerDrugRead,cmdSUDrugUpdate,cmdSUBaseInfoRead,cmdSUBaseInfoInput,cmdSUDoctorInfo,cmdSUDoctorChoose,cmdSUDocInfo,
	cmdSUHealInfoInput,cmdServerLogOn,cmdSUPlatInfoRead,cmdSURegVery,cmdSURegVery1,cmdSUReg,cmdSUReg1,cmdServerPWReset,
	cmdServerVeriCode,cmdSUPWResetCode,cmdSUWel,cmdSULatestHealRead,cmdSUHisHealRead,cmdSURepRead,cmdSUExcepRead,cmdSUSendCode,
	cmdSUSubCode,cmdSUNewPass,cmdSUMessRead,cmdSUMessSend,//�û��˽ӿ�
	cmdSMAddUser,cmdSMQueUser,cmdSMChgUserBasInfo,cmdSMQueUserDrug,cmdSMChgUserDrug,
	cmdSMQueUserExcep,cmdSMQueUserMess,cmdSMQueUserRep,cmdSMQueUserUpload,cmdSMAddDoc,cmdSMQueDoc,
	cmdSMChgDocBasInfo,cmdSMQueDocRep,cmdSMQueDocMess,cmdSMQueUser1,cmdSMQueDoc1,cmdSMQueCSM,cmdSMAddManSR,
	cmdSMQueCSR,cmdSMAddManSM,cmdSMQueTM,cmdSMAddManTP,cmdSMQueTP,cmdSMAddManTM,cmdSMQueDM,cmdSMAddManDP,
	cmdSMQueDP,cmdSMAddManDM,cmdSMQueMan,cmdSMQue,cmdSMSendMess,cmdSMSendMessOT,cmdSMAddSeriManu,cmdSMAddSeriBat,
	cmdSMQueSeri,cmdSMLogin//����˽ӿ�
} cmdServer;

enum{
	cmdManQueEmplyee=200,cmdManLogin1
};