#pragma once


// player dialog

class player : public CDialogEx
{
	DECLARE_DYNAMIC(player)

public:
	player(CWnd* pParent = NULL);   // standard constructor
	virtual ~player();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
