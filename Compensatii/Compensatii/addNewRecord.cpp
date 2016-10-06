// addNewRecord.cpp : implementation file
//

#include "stdafx.h"
#include "Compensatii.h"
#include "addNewRecord.h"
#include "afxdialogex.h"


// addNewRecord dialog

IMPLEMENT_DYNAMIC(addNewRecord, CDialogEx)

addNewRecord::addNewRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_newRecord, pParent)
	, realimentAcordJT(0)
	, realimentAcordMT(0)
	, realimentAcordIT(0)
	, valCompensationsJTRealim(0)
	, valCompensationsMTRealim(0)
	, valCompensationsITRealim(0)
{

}

addNewRecord::~addNewRecord()
{
}

void addNewRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, realimentAcordJT);
	DDX_Text(pDX, IDC_EDIT2, realimentAcordMT);
	DDX_Text(pDX, IDC_EDIT3, realimentAcordIT);
	DDX_Text(pDX, IDC_EDIT4, valCompensationsJTRealim);
	DDX_Text(pDX, IDC_EDIT5, valCompensationsMTRealim);
	DDX_Text(pDX, IDC_EDIT6, valCompensationsITRealim);
}


BEGIN_MESSAGE_MAP(addNewRecord, CDialogEx)
	ON_COMMAND(ID_FILE_NEWRECORD, &addNewRecord::OnFileNewrecord)
	ON_EN_CHANGE(IDC_EDIT1, &addNewRecord::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &addNewRecord::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// addNewRecord message handlers


void addNewRecord::OnFileNewrecord()
{
	// TODO: Add your command handler code here
}


void addNewRecord::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void addNewRecord::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
}
