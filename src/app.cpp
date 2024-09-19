#include "app.h"
#include "mainframe.h"
#include "pricinglibrary.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    PricingLibrary::Initialize();
    MainFrame* frame = new MainFrame("Flippity");
    frame->SetClientSize(1200, 800);
    frame->Center();
    frame->Show();
    return true;
}
