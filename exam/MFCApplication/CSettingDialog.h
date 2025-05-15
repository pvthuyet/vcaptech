#pragma once
#include "afxdialogex.h"


// CSettingDialog dialog

class CSettingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDialog)

public:
	CSettingDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSettingDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_labelCtrl;
	CComboBox m_comboxCtrl;

private:
	void ArrangeLayout(int cx, int cy);
public:
	virtual BOOL OnInitDialog();
	CString m_labelStr;
	afx_msg void OnCbnSelchangeSettingCmb();
};
