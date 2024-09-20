#include "mainframe.h"
#include "timing.h"
#include "pricinglibrary.h"
#include "clipboard.h"
#include <format>
#include "conversions.h"

void MainFrame::GetFlips()
{
    while (true)
    {
        if (Timing::CurrentSecondInMinute() == 0)
        {
            const std::vector<std::unique_ptr<Item>> flips = PricingLibrary::GetFlips();
            
            if (!flips.empty())
            {
                Clipboard::Write(std::format("/viewauction {}", flips.back()->GetUuid()));
            }
            
            std::string buffer;
            for (const auto& flip : flips)
            {
                buffer += flip->GetUuid() + " " + Conversions::ToNarrowString(flip->GetName()) + " "
                    + std::to_string(flip->GetPrice())  + " " + std::to_string(flip->GetProfit()) + "\n";
            }

            // safely update GUI from background thread
            wxEvtHandler::CallAfter([this, buffer]()
                    {
                        this->m_textCtrl->SetValue(buffer);
                    });
        
            Timing::Sleep(1'500);
        }   
        Timing::Sleep(100);
    }
}
