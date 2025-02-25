#ifndef TEXT_ANALYZER_H
#define TEXT_ANALYZER_H

#include "TextStats.h"
#include <string_view>

TextStats analyzeText(std::string_view text);

#endif // TEXT_ANALYZER_H