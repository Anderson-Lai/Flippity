#include "mainframe.h"
#include <wx/event.h>
#include <wx/wx.h>
#include <thread>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    this->m_panels[Panels::MainPanel] = new wxPanel(this); 
    this->DrawMainPanel();

    std::thread([this]()
            {
                this->GetFlips();
            }).detach();
}

void MainFrame::DrawMainPanel()
{
    wxPanel* panel = this->m_panels.at(Panels::MainPanel);
    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    this->m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(450, 350),
           wxTE_READONLY);

    sizer->Add(this->m_textCtrl, wxSizerFlags(0).CenterHorizontal().Border(wxALL, 25));

    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

