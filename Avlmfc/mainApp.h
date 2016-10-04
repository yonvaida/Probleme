#pragma once
#include <afxwin.h>

class winApp :public CWinApp {
	BOOL InitInstance() {
		return TRUE;
	};
};
class mainFrame :public CFrameWnd {
public:
	mainFrame() {
		Create(NULL, "Test Frame");

	};

};