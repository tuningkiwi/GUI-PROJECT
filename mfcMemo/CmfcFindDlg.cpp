#include "pch.h"
#include "CmfcFindDlg.h"
#include "framework.h"
#include "mfcMemo.h"
#include "mfcMemoDlg.h"
#include "afxdialogex.h"



BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	mStr = "";
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


//BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)
//{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

//	return CDialogEx::PreTranslateMessage(pMsg);
//}
BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG) {

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