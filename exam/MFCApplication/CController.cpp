#include "pch.h"
#include "CController.h"

#include "CModel.h"
#include "MFCApplicationDlg.h"

CController::CController(CModel& model, CMFCApplicationDlg& view)
    : m_model(model) 
    , m_view(view) 
{
}

void CController::updateGroundWaterMethod(int selectedIndex)
{
    m_model.setGroundWaterMethodSelectedIndex(selectedIndex);
    m_view.m_label1Str = m_model.getGroundWaterMethodSelected().c_str();
    m_view.UpdateData(FALSE);
}

void CController::updateThermalMethod(int selectedIndex)
{
    m_model.setThermalMethodSelectedIndex(selectedIndex);
    m_view.m_label2Str = m_model.getThermalMethodSelected().c_str();
    m_view.UpdateData(FALSE);
}
