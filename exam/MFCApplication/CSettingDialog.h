#pragma once
#include "afxdialogex.h"
#include <vector>


// CSettingDialog dialog

class CSettingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDialog)

public:
	CSettingDialog(const CString& labelText, int selectedIndex, const std::vector<CString>& items, CWnd* pParent = nullptr);   // standard constructor
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

	int getSelectedIndex() const { return m_selectedIndex; }
private:
	int m_selectedIndex;
	std::vector<CString> m_comboBoxitems;
};
