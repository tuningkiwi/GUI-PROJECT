#pragma once
#include <afxdialogex.h>
class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = ""; //찾는 문자 
    CString rStr = ""; //replace 문자 

    CmfcFindDlg();
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreTranslateMessage(MSG* pMsg);

    
    //    virtual BOOL PreTranslateMessage(MSG* pMsg);
    DECLARE_MESSAGE_MAP()
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    
};

