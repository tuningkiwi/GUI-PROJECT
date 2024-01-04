
// mfcMemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcMemo.h"
#include "mfcMemoDlg.h"
#include "afxdialogex.h"
#include "CmfcFindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <cstring>
#include <iostream>
#include <fstream>


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CmfcMemoDlg 대화 상자



CmfcMemoDlg::CmfcMemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MEMO, mEditMemo);
}

BEGIN_MESSAGE_MAP(CmfcMemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_OPEN, &CmfcMemoDlg::OnMenuOpen)
	ON_COMMAND(ID_MENU_ABOUT, &CmfcMemoDlg::OnMenuAbout)
	//ON_COMMAND(32780, &CmfcMemoDlg::OnMenuAbout)
	ON_COMMAND(ID_MENU_FIND, &CmfcMemoDlg::OnMenuFind)
	ON_COMMAND(ID_MENU_NEXTFIND, &CmfcMemoDlg::OnMenuNextfind)
END_MESSAGE_MAP()


// CmfcMemoDlg 메시지 처리기

BOOL CmfcMemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcMemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcMemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcMemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcMemoDlg::OnMenuOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//char buf[512];//FILE READ BUFFER 
	CString str;
		
	OPENFILENAME ofn;
	//wchar_t wbuf[100] = {0};// ofn 의 file name 저장공간 
	char fName[100] = "";
	memset(&ofn, 0, sizeof(OPENFILENAME));
	//ZeroMemory(&ofn, sizeof(ofn)); //메모리 공간 청소 
	//ZeroMemory(wbuf, sizeof(wbuf)); //메모리 공간 청소 

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = fName;//FILE NAME 저장공간
	ofn.nMaxFile = 100; 
	//ofn.lpstrDefExt = L"";//유니코드 문자 집합 사용 시 
	ofn.lpstrDefExt = "";

	if (!GetOpenFileName(&ofn)) {//Return true or false 
		return; 
	}

	//str = wbuf; //cstirng <== wchar, cstring <== char


	//절대경로 
	//FILE* fp = fopen("C:\\Users\\EMBEDDED\\source\\repos\\winapp\\mfcMemo\\hello_ANSI.txt", "rb");
	//상대경로로 설정시, 솔루션 파일 말고, 프로젝트 파일 폴더 기준으로 상대경로 지정하면 됨.
	//FILE* fp = fopen("..\\hello_ANSI.txt", "rb"); 
	
	//C언어의 표준함수 ANSI encoding 
	//FILE* fp = fopen(fName, "rb");//ANSI 형태로만 받음 그래서 CStringA로 강제 변환
	//CStringA(str)


	// 최대 512까지 읽고, 중간에 \r\n을 만날 때, 거기까지만 읽어옴. 
	
	/*
	while (fgets(buf, 512, fp)) {//buf에다가 읽어온 데이터를 저장 
		((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(str);//str에 데이터를 저장하겠다는 뜻
		//GetDlgItem(IDC_EDIT1)->SetWindowTextW(str+buf);//저장한 str을 print 하겠다. 
		SetDlgItemText(IDC_EDIT1, str+buf);
	}
	*/

	//헤더파일 iostream cstring fstream 추가 필요 
	//c++ stream 표준. UTF-8 encoding (유니코드 문자를 지원하는 가변길이 문자 인코딩 방식) 
	wchar_t buf1[512];
	std::locale::global(std::locale(".UTF-8"));
	std::wifstream ff;
	ff.open(fName);
	for (; ff.getline(buf1, 512);) {
		str = buf1;
		AddText(str); AddText("\r\n");
	}

}


void CmfcMemoDlg::OnMenuAbout() //도움말 about 메뉴 기능 
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CAboutDlg dlg;
	dlg.DoModal();


}


void CmfcMemoDlg::OnMenuFind()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CmfcFindDlg dlg;
	if (dlg.DoModal() == IDOK) {
		CString s;
		mEditMemo.GetWindowText(s);
		saveData = dlg.mStr;
		int start = s.Find(dlg.mStr);
		int end = start + dlg.mStr.GetLength();
		start_pos = start + 1;
		mEditMemo.SetSel(start,end);
		
		//AddText(dlg.mStr);
	}
}


void CmfcMemoDlg::AddText(CString s) {

	CString str;
	((CEdit*)GetDlgItem(IDC_EDIT_MEMO))->GetWindowText(str);//str에 데이터를 저장하겠다는 뜻
	//GetDlgItem(IDC_EDIT1)->SetWindowTextW(str+buf);//저장한 str을 print 하겠다. 
	str += s;
	SetDlgItemText(IDC_EDIT1, str);
}



void CmfcMemoDlg::OnMenuNextfind()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
		CString s;
		mEditMemo.GetWindowText(s);
		
		start_pos = s.Find(saveData,start_pos);

		int end = start_pos + saveData.GetLength();
		mEditMemo.SetSel(start_pos, end);
		start_pos++;
	
}
