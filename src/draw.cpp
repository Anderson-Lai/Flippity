#include "mainframe.h"

void MainFrame::DrawMainPanel()
{
    wxPanel* panel = this->m_panels.at(Panels::MainPanel);

    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* utilsSizer = new wxBoxSizer(wxVERTICAL);
    
    this->m_flipsIn = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(125, 75),
            wxTE_MULTILINE | wxTE_CENTER);
    this->m_flipsIn->SetForegroundColour(wxColour(255, 255, 255));

    this->m_timeElapsed = new wxTextCtrl(panel, wxID_ANY, "Time Elapsed:\n", wxDefaultPosition, wxSize(125, 75),
            wxTE_MULTILINE | wxTE_CENTER);
    this->m_timeElapsed->SetForegroundColour(wxColor(255, 255, 255));

    this->m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(510, 425),
            wxTE_READONLY | wxTE_MULTILINE | wxTE_CENTER);
    this->m_textCtrl->SetForegroundColour(wxColour(255, 255, 255));

    this->m_flipsIn->Disable();
    this->m_timeElapsed->Disable();
    
    utilsSizer->Add(this->m_flipsIn, wxSizerFlags().Border(wxBOTTOM, 25));
    utilsSizer->Add(this->m_timeElapsed);
    sizer->Add(utilsSizer);
    sizer->Add(this->m_textCtrl, wxSizerFlags().Border(wxLEFT, 55));

    panelSizer->Add(sizer, wxSizerFlags().CenterHorizontal().Border(wxALL, 35));

    panel->SetSizer(panelSizer);
    sizer->SetSizeHints(this);
}

