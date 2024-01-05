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
	if (mode == FIND_MODE ) {//ã�� ��� 
		((CEdit*)GetDlgItem(IDC_EDIT_FIND))->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_REPLACE))->ShowWindow(SW_HIDE);
	}
	else if(mode == REPLACE_MODE){//�ٲٱ� ��� 
		((CEdit*)GetDlgItem(IDC_EDIT_FIND))->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_REPLACE))->ShowWindow(SW_SHOW);
	}
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
					EndDialog(IDOK);//��� ���ڸ� �ݰ� IDOK�� ��ȯ�մϴ� 
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