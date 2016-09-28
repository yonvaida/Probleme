#include <afxwin.h>
#include "resource.h"
#include "mainApp.h"
#include "mainFrame.h"

class onlineTVPlayer :public CWinApp {
	BOOL InitInstance() {
		this->m_pMainWnd = new OnlineTVFrame();
		this->m_pMainWnd->ShowWindow(SW_NORMAL);
		return TRUE;
	}
};
onlineTVPlayer tvPlayer;