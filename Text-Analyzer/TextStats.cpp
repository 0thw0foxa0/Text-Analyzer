#include "TextStats.h"
#include <iostream>
#include <vector>
#include <algorithm>

void TextStats::print() const {
    std::cout << "Analyze text:\n";
    std::cout << "Total words: " << totalWords << '\n';
    std::cout << "Count of unic word : " << wordFrequency.size() << '\n';
    std::cout << "Count symbols (without spases): " << characters << '\n';
    std::cout << "Count sentences: " << sentences << '\n';

    if (wordFrequency.empty()) return;

    std::cout << "\nTop 5 words:\n";
    std::vector<std::pair<std::string, int>> freq(wordFrequency.begin(), wordFrequency.end());
    std::partial_sort(freq.begin(), freq.begin() + std::min(5, static_cast<int>(freq.size())),
        freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
    for (int i = 0; i < std::min(5, static_cast<int>(freq.size())); ++i) {
        std::cout << freq[i].first << ": " << freq[i].second << " times\n";
    }
}