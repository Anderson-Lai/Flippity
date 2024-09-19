#pragma once
#include <string>

namespace Clipboard
{
    int Write(const char* text);
    int Write(const std::string& text);
}
