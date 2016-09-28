// player.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "player.h"
#include "afxdialogex.h"


// player dialog

IMPLEMENT_DYNAMIC(player, CDialogEx)

player::player(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

player::~player()
{
}

void player::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(player, CDialogEx)
END_MESSAGE_MAP()


// player message handlers
