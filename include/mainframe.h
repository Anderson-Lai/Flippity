#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
private:
    void HandleExit(wxCommandEvent& evt);
    void GetFlips();
private:
    wxTextCtrl* m_textCtrl;
};
