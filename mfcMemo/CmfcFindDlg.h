#pragma once
#include <afxdialogex.h>

#define FIND_MODE 0
#define REPLACE_MODE 1
#define REPLACE_ONE 0
#define REPLACE_ALL 1

class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = ""; //찾는 문자 
    CString rStr = ""; //replace 문자 
    int mode = FIND_MODE;
    int replace_option = REPLACE_ONE;

    CmfcFindDlg();
    CmfcFindDlg(int mode);

    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreTranslateMessage(MSG* pMsg);

    
    //    virtual BOOL PreTranslateMessage(MSG* pMsg);
    DECLARE_MESSAGE_MAP()
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    
    afx_msg void OnBnClickedReplaceOne();
    afx_msg void OnBnClickedReplaceAll();
    afx_msg void OnBnClickedButtonFind();
};

