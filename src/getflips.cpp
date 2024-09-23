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
            const auto begin = Timing::Now();
            const std::vector<std::unique_ptr<Item>> flips = PricingLibrary::GetFlips();
            const auto end = Timing::Now();
            
            const long long elapsed = 
                std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            
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
            wxEvtHandler::CallAfter([this, buffer, elapsed]()
                    {
                        this->m_textCtrl->SetValue(buffer);
                        this->m_timeElapsed->SetValue("Time elapsed:\n" + std::to_string(elapsed) + "ms");
                    });
        
            Timing::Sleep(1'500);
        }   
        Timing::Sleep(100);
    }
}
