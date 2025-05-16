
// MFCApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "CSettingDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
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


// CMFCApplicationDlg dialog



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
	, m_label1Str(_T(""))
	, m_label2Str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_LABEL_1, m_label1Ctrl);
	DDX_Control(pDX, IDC_LABEL_2, m_label2Ctrl);
	DDX_Text(pDX, IDC_LABEL_1, m_label1Str);
	DDX_Text(pDX, IDC_LABEL_2, m_label2Str);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationDlg::OnBnClickedButton2)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCApplicationDlg message handlers

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rect;
	GetClientRect(&rect);
	if (rect.Width() > 0 && rect.Height() > 0) {
		ArrangeLayout(rect.Width(), rect.Height());
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplicationDlg::OnBnClickedButton1()
{
	CSettingDialog dlg(_T("Ground Water Method:"), 1);
	dlg.DoModal();
	//m_label1Str = dlg.getSelectedText();
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnBnClickedButton2()
{
	CSettingDialog dlg(_T("Thermal Method:"), 2);
	dlg.DoModal();
	//m_label2Str = dlg.getSelectedText();
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	ArrangeLayout(cx, cy);
}

void CMFCApplicationDlg::ArrangeLayout(int cx, int cy)
{
	if (m_button1.GetSafeHwnd() == nullptr)
		return; // Controls not yet created

	const int padding = 10;
	const int rowHeight = 30;
	const int controlWidth = (cx - (3 * padding)) / 2;
	const int labelHeight = cy - rowHeight - (padding * 3);

	// Row 1: Buttons
	m_button1.MoveWindow(padding, padding, controlWidth, rowHeight);
	m_button2.MoveWindow(padding * 2 + controlWidth, padding, controlWidth, rowHeight);

	// Row 2: Labels
	m_label1Ctrl.MoveWindow(padding, padding * 2 + rowHeight, controlWidth, labelHeight);
	m_label2Ctrl.MoveWindow(padding * 2 + controlWidth, padding * 2 + rowHeight, controlWidth, labelHeight);
}
