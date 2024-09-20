#include "mainframe.h"
#include "pricinglibrary.h"

void MainFrame::HandleExit(wxCommandEvent& evt)
{
    PricingLibrary::CleanUp();    
    evt.Skip();
}
