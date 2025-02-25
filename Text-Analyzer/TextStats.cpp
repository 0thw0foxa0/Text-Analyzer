#include "TextStats.h"
#include <iostream>

void TextStats::print() const {
    std::cout << "Анализ текста:\n";
    std::cout << "Количество слов: " << totalWords << '\n';
    std::cout << "Количество символов (без пробелов): " << characters << '\n';
    std::cout << "Количество предложений: " << sentences << '\n';
}