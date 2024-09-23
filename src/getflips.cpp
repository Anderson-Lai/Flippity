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
            for (long long i = flips.size() - 1; i > -1; i--)
            {
                buffer += std::format("Auction uuid: {}\nProfit: {}\nItem name: {}\nItem price: {}\n\n",
                        flips[i]->GetUuid(), flips[i]->GetProfit(),
                        Conversions::ToNarrowString(flips[i]->GetName()), flips[i]->GetPrice());
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
