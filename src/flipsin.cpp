#include "mainframe.h"
#include "timing.h"

void MainFrame::FlipsIn()
{
    while (true)
    {
        const unsigned long long now = Timing::CurrentSecondInMinute();
        const std::string text = now < 3 ? "NOW!" : std::to_string(60 - now) + "s";

        wxEvtHandler::CallAfter([this, text]()
                {
                    this->m_flipsIn->SetValue("Flips in:\n" + text);
                });

        Timing::Sleep(100);
    }
}
