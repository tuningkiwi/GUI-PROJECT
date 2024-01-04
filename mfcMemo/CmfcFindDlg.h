#pragma once
#include <afxdialogex.h>
class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = "";

    CmfcFindDlg();
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreTranslateMessage(MSG* pMsg);

    
    //    virtual BOOL PreTranslateMessage(MSG* pMsg);
    DECLARE_MESSAGE_MAP()
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    
};

