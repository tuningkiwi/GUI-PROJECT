#include "pch.h"
#include "CmfcFindDlg.h"
#include "framework.h"
#include "mfcMemo.h"
#include "mfcMemoDlg.h"
#include "afxdialogex.h"

#define FIND_MODE 0
#define REPLACE_MODE 1

BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	mStr = "";
	if (mode == FIND_MODE ) {//찾기 모드 
		((CEdit*)GetDlgItem(IDC_EDIT_FIND))->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_REPLACE))->ShowWindow(SW_HIDE);
	}
	else if(mode == REPLACE_MODE){//바꾸기 모드 
		((CEdit*)GetDlgItem(IDC_EDIT_FIND))->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_REPLACE))->ShowWindow(SW_SHOW);
	}
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG) {

}

CmfcFindDlg::CmfcFindDlg(int mode) : CDialogEx(IDD_FIND_DIALOG) {
	this->mode = mode;
}

void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, Memo);
}


void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
		case VK_RETURN:
			GetDlgItem(IDC_EDIT_FIND)->GetWindowText(mStr);
			break;
		case VK_ESCAPE:
			mStr = "";
			break;
		default: 
			break;
	}


	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg) {
	switch (pMsg->message) {
		case (WM_KEYDOWN):
			switch (pMsg->wParam) {
				case VK_RETURN:
					GetDlgItem(IDC_EDIT_FIND)->GetWindowText(mStr);	
					GetDlgItem(IDC_EDIT_REPLACE)->GetWindowText(rStr);
					EndDialog(IDOK);//모달 상자를 닫고 IDOK를 반환합니다 
					break;
				case VK_ESCAPE:
					mStr = "";
					EndDialog(IDCANCEL);
					break;
				default:
					break;
			}
			break;
		default: 
			break;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}