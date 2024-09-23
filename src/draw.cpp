#include "mainframe.h"

void MainFrame::DrawMainPanel()
{
    wxPanel* panel = this->m_panels.at(Panels::MainPanel);
    
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* utilsSizer = new wxBoxSizer(wxVERTICAL);
    
    this->m_flipsIn = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(125, 75),
            wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
    this->m_timeElapsed = new wxTextCtrl(panel, wxID_ANY, "Time Elapsed:\n", wxDefaultPosition, wxSize(125, 75),
            wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
    this->m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(510, 425),
           wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
    
    utilsSizer->Add(this->m_flipsIn, wxSizerFlags().Border(wxALL, 25));
    utilsSizer->Add(this->m_timeElapsed, wxSizerFlags().Border(wxLEFT | wxRIGHT | wxBOTTOM, 25));
    sizer->Add(utilsSizer);
    sizer->Add(this->m_textCtrl, wxSizerFlags().Border(wxALL, 25));

    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

