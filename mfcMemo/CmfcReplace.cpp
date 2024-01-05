// CmfcReplace.cpp: 구현 파일
//

#include "pch.h"
#include "mfcMemo.h"
#include "afxdialogex.h"
#include "CmfcReplace.h"


// CmfcReplace 대화 상자

IMPLEMENT_DYNAMIC(CmfcReplace, CDialogEx)

CmfcReplace::CmfcReplace(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REPLACE_DIALOG, pParent)
{
	mStrFind = "";
	mStrReplace = "";
}

CmfcReplace::~CmfcReplace()
{
}

void CmfcReplace::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CmfcReplace, CDialogEx)
	ON_BN_CLICKED(IDC_REPLACE_COMPLETE, &CmfcReplace::OnBnClickedReplaceComplete)
END_MESSAGE_MAP()


// CmfcReplace 메시지 처리기


BOOL CmfcReplace::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



BOOL CmfcReplace::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message) {

		case (WM_KEYDOWN): {

			switch (pMsg->wParam) {

				case VK_ESCAPE: 
					EndDialog(IDCANCEL);//그 시점에서 종료예약임(즉시종료X)
					break;//현재 함수가 끝난 시점에 break에서 dialog가 종료 됨. 
				
				case VK_RETURN: 
					OnBnClickedReplaceComplete();
					//((CEdit*)GetDlgItem(IDC_EDIT_FIND2))->GetWindowText(mStrFind);
					//GetDlgItem(IDC_EDIT_REPLACE2)->GetWindowText(mStrReplace);
					//EndDialog(IDOK);
					break;
			}
		}	
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


//os가 타이머에의해서 이벤트 큐에서 아래 코드를 호출 실행시킴
//이런 콜백함수는 로컬에서도 호출할 수 있다
void CmfcReplace::OnBnClickedReplaceComplete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CEdit*)GetDlgItem(IDC_EDIT_FIND2))->GetWindowText(mStrFind);
	GetDlgItem(IDC_EDIT_REPLACE2)->GetWindowText(mStrReplace);
	EndDialog(IDOK);
}
