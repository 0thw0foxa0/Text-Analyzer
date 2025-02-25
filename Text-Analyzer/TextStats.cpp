#include "TextStats.h"
#include <iostream>
#include <vector>
#include <algorithm>

void TextStats::print() const {
    std::cout << "������ ������:\n";
    std::cout << "���������� ����: " << totalWords << '\n';
    std::cout << "���������� ���������� ����: " << wordFrequency.size() << '\n';
    std::cout << "���������� �������� (��� ��������): " << characters << '\n';
    std::cout << "���������� �����������: " << sentences << '\n';

    if (wordFrequency.empty()) return;

    std::cout << "\n���-5 ����� ������ ����:\n";
    std::vector<std::pair<std::string, int>> freq(wordFrequency.begin(), wordFrequency.end());
    std::partial_sort(freq.begin(), freq.begin() + std::min(5, static_cast<int>(freq.size())),
        freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
    for (int i = 0; i < std::min(5, static_cast<int>(freq.size())); ++i) {
        std::cout << freq[i].first << ": " << freq[i].second << " ���\n";
    }
}