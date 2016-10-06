#pragma once


// addNewRecord dialog

class addNewRecord : public CDialogEx
{
	DECLARE_DYNAMIC(addNewRecord)

public:
	addNewRecord(CWnd* pParent = NULL);   // standard constructor
	virtual ~addNewRecord();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_newRecord };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileNewrecord();
	int realimentAcordJT;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	int realimentAcordMT;
	int realimentAcordIT;
	int valCompensationsJTRealim;
	int valCompensationsMTRealim;
	int valCompensationsITRealim;
	afx_msg void OnCbnSelchangeCombo2();
};
