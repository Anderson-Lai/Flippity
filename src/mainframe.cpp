#include "mainframe.h"
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

    std::thread([this]()
            {
                this->FlipsIn();
            }).detach();
}

