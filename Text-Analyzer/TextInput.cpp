#include "TextInput.h"
#include <iostream>
#include <fstream>
#include <iterator>

std::string readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File opening is false: " << filename << '\n';
        return {};
    }
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return text;
}

std::string readFromInput() {
    std::cout << "Input text (Ctrl+Z  and enter for end):\n";
    std::string text, line;
    while (std::getline(std::cin, line)) {
        text += line + '\n';
    }
    return text;
}