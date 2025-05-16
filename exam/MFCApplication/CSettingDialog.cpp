// CSettingDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication.h"
#include "afxdialogex.h"
#include "CSettingDialog.h"


// CSettingDialog dialog

IMPLEMENT_DYNAMIC(CSettingDialog, CDialogEx)

CSettingDialog::CSettingDialog(const CString& labelText, int selectedIndex, const CStringArray& items, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTING_DIALOG, pParent)
	, m_labelStr(labelText)
	, m_selectedIndex(selectedIndex)
	, m_items(items)
{

}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SETTING_LABEL, m_labelCtrl);
	DDX_Control(pDX, IDC_SETTING_CMB, m_comboxCtrl);
	DDX_Text(pDX, IDC_SETTING_LABEL, m_labelStr);
	DDX_CBIndex(pDX, IDC_SETTING_CMB, m_selectedIndex);
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialogEx)
END_MESSAGE_MAP()


// CSettingDialog message handlers



BOOL CSettingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CRect rect;
	GetClientRect(&rect);
	if (rect.Width() > 0 && rect.Height() > 0) {
		ArrangeLayout(rect.Width(), rect.Height());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDialog::ArrangeLayout(int cx, int cy)
{
	if (m_labelCtrl.GetSafeHwnd() == nullptr)
		return; // Controls not yet created

	const int padding = 10;
	const int labelHeight = 30;
	const int w = (cx - (2 * padding));
	const int cmbHeight = cy - labelHeight - (padding * 2);

	m_labelCtrl.MoveWindow(padding, padding, w, labelHeight);
	m_comboxCtrl.MoveWindow(padding, padding + labelHeight, w, cmbHeight);
}

