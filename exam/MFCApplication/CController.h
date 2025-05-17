#pragma once

class CModel;
class CMFCApplicationDlg;

class CController final
{
public:
    CController(CModel& model, CMFCApplicationDlg& view);
    void updateGroundWaterMethod(int selectedIndex);
    void updateThermalMethod(int selectedIndex);

private:
    CModel& m_model;
    CMFCApplicationDlg& m_view;
};

