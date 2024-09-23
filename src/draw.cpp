#include "mainframe.h"
#include <wx/wx.h>

void MainFrame::DrawMainPanel()
{
    wxPanel* panel = this->m_panels.at(Panels::MainPanel);
    
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    
    this->m_flipsIn = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(125, 75),
            wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
    this->m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(450, 350),
           wxTE_READONLY | wxTE_MULTILINE);
    this->m_timeElapsed = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(125, 75),
            wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
//    sizer->Add(this->m_textCtrl, wxSizerFlags(0).CenterHorizontal().Border(wxALL, 25));
    sizer->Add(this->m_flipsIn, wxSizerFlags().Border(wxALL, 25));
    sizer->Add(this->m_textCtrl, wxSizerFlags().Border(wxALL, 50));
    sizer->Add(this->m_timeElapsed, wxSizerFlags().Border(wxALL, 25));

    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

