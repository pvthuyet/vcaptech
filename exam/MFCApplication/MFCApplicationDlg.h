
// MFCApplicationDlg.h : header file
//

#pragma once

#include "cmodel.h"
#include "ccontroller.h"

// CMFCApplicationDlg dialog
class CMFCApplicationDlg : public CDialogEx
{
private:
	CButton m_button1;
	CButton m_button2;
	CStatic m_label1Ctrl;
	CStatic m_label2Ctrl;
	CString m_label1Str;
	CString m_label2Str;
	CModel m_model;
    CController m_controller;

// Construction
public:
	CMFCApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSize(UINT nType, int cx, int cy);

private:
	void ArrangeLayout(int cx, int cy);
};
