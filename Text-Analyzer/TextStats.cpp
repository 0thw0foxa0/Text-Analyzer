#include "TextStats.h"
#include <iostream>

void TextStats::print() const {
    std::cout << "������ ������:\n";
    std::cout << "���������� ����: " << totalWords << '\n';
    std::cout << "���������� �������� (��� ��������): " << characters << '\n';
    std::cout << "���������� �����������: " << sentences << '\n';
}