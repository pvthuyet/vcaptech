#pragma once

class CModel;
class CMFCApplicationDlg;

class CController final
{
public:
    CController(CModel& model, CMFCApplicationDlg& view);

private:
    CModel& m_model;
    CMFCApplicationDlg& m_view;
};

