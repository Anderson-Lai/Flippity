#pragma once
#include <wx/wx.h>
#include <unordered_map>

enum Panels
{
    MainPanel
};

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void DrawMainPanel();
private:
    void HandleExit(wxCommandEvent& evt);
    void GetFlips();
    void FlipsIn();
private:
    std::unordered_map<Panels, wxPanel*> m_panels;
private:
    wxTextCtrl* m_textCtrl;
    wxTextCtrl* m_timeElapsed;
    wxTextCtrl* m_flipsIn;
};
