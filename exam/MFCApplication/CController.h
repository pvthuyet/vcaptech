#pragma once

class ViewModel;
class CMFCApplicationDlg;

class CController final
{
public:
    CController(ViewModel& model, CMFCApplicationDlg& view);
    virtual ~CController();

    void updateGroundWaterMethod(int selectedIndex);
    void updateThermalMethod(int selectedIndex);

private:
    ViewModel& m_model;
    CMFCApplicationDlg& m_view;
};

