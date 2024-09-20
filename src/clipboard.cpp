#include "clipboard.h"
#include <wx/clipbrd.h>

int Clipboard::Write(const char* text)
{
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(text));
        wxTheClipboard->Close();
        return 0;
    }
    return 1;
}

int Clipboard::Write(const std::string& text)
{
    return Clipboard::Write(text.c_str());
}
