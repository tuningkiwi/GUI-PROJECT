
// mfcMemoDlg.h: 헤더 파일
//

#pragma once


// CmfcMemoDlg 대화 상자
class CmfcMemoDlg : public CDialogEx
{
// 생성입니다.
private:
	CString sFind = "";//FIND에 입력한 단어
	CString sReplace = "";//REPLACE에 입력한 단어 
	int start_pos = 0;
	int begin_pos = 0;
	int mEncoding = 0;// [0] ANSI  [1] UTF-8
	int fSize = 0;
	CString fName = "";

public:
	CmfcMemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMEMO_DIALOG };
#endif

	protected:
	//accel 변수 선언
	HACCEL accel;
	CStatusBarCtrl mStatusBar;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CEdit Memo;
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuFind();
	void AddText(CString s);
	CEdit mEditMemo;
	afx_msg void OnMenuNextfind();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnMenuUtf8();
	afx_msg void OnMenuAnsi();
	afx_msg void OnMenuReplace();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuReplaceNext();
	afx_msg void OnMenuFont();
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
