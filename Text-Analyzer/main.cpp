#include "TextAnalyzer.h"
#include "TextInput.h"
#include <iostream>

int main() {
    std::string inputText;
    std::cout << "Enter text manually (1) or from file (2)? ";
    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") {
        inputText = readFromInput();
    }
    else if (choice == "2") {
        std::cout << "Enter file name: ";
        std::string filename;
        std::getline(std::cin, filename);
        inputText = readFromFile(filename);
    }
    else {
        std::cout << "Wrong!\n";
        return 1;
    }

    if (inputText.empty()) {
        std::cout << "Text file is empy or wrong direction!\n";
        return 1;
    }

    auto stats = analyzeText(inputText);
    stats.print();
    return 0;
}