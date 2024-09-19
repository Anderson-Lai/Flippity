#include "mainframe.h"
#include "pricinglibrary.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

void MainFrame::HandleExit(wxCommandEvent& evt)
{
    PricingLibrary::CleanUp();    
    evt.Skip();
}
