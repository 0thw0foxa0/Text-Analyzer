#include "TextAnalyzer.h"
#include <cctype>

inline bool isWordSeparator(char c) {
    return std::isspace(c) || c == ',' || c == ';' || c == ':';
}

inline bool isSentenceEnd(char c, char next) {
    return (c == '.' || c == '!' || c == '?') && !std::isalnum(next);
}

TextStats analyzeText(std::string_view text) {
    TextStats stats;
    std::string currentWord;
    currentWord.reserve(32);

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        char next = (i + 1 < text.length()) ? text[i + 1] : ' ';

        if (!std::isspace(c)) stats.characters++;

        if (isWordSeparator(c) || isSentenceEnd(c, next)) {
            if (!currentWord.empty()) {
                stats.totalWords++;
                stats.wordFrequency[currentWord]++;
                currentWord.clear();
            }
        }
        else if (std::isalnum(c)) {
            currentWord += std::tolower(c);
        }

        if (isSentenceEnd(c, next)) stats.sentences++;
    }

    if (!currentWord.empty()) {
        stats.totalWords++;
        stats.wordFrequency[currentWord]++;
    }

    return stats;
}