#include "mainFrame.h"
popupButton::popupButton() {
	
}
OnlineTVFrame::OnlineTVFrame() {
	
	popupButton * Button1 = new popupButton();
	Create(NULL, "new frame");
	Button1->Create("New Button", WS_SYSMENU | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 10, 200, 200), this, 1);
	
	//MessageBox("Clicked");
}