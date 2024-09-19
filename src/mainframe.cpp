#include "mainframe.h"
#include "pricinglibrary.h"
#include <wx/event.h>
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    this->m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(450, 350), wxTE_READONLY);

    std::thread([this]()
            {
                this->GetFlips();
            }).detach();

    sizer->Add(this->m_textCtrl, wxSizerFlags(0).CenterHorizontal().Border(wxALL, 25));

    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

void MainFrame::HandleExit(wxCommandEvent& evt)
{
    PricingLibrary::CleanUp();    
    evt.Skip();
}
