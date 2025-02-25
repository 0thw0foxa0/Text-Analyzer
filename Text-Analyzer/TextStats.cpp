#include "TextStats.h"
#include <iostream>
#include <vector>
#include <algorithm>

void TextStats::print() const {
    std::cout << "Анализ текста:\n";
    std::cout << "Количество слов: " << totalWords << '\n';
    std::cout << "Количество уникальных слов: " << wordFrequency.size() << '\n';
    std::cout << "Количество символов (без пробелов): " << characters << '\n';
    std::cout << "Количество предложений: " << sentences << '\n';

    if (wordFrequency.empty()) return;

    std::cout << "\nТоп-5 самых частых слов:\n";
    std::vector<std::pair<std::string, int>> freq(wordFrequency.begin(), wordFrequency.end());
    std::partial_sort(freq.begin(), freq.begin() + std::min(5, static_cast<int>(freq.size())),
        freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
    for (int i = 0; i < std::min(5, static_cast<int>(freq.size())); ++i) {
        std::cout << freq[i].first << ": " << freq[i].second << " раз\n";
    }
}