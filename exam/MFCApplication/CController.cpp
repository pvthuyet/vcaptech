#include "pch.h"
#include "CController.h"

#include "CModel.h"
#include "MFCApplicationDlg.h"

CController::CController(CModel& model, CMFCApplicationDlg& view)
    : m_model(model) 
    , m_view(view) 
{
}   
