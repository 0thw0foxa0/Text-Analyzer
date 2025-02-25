#ifndef TEXT_STATS_H
#define TEXT_STATS_H

#include <unordered_map>
#include <string>

struct TextStats {
    int totalWords = 0;
    int characters = 0;
    int sentences = 0;
    std::unordered_map<std::string, int> wordFrequency;

    void print() const;
};

#endif // TEXT_STATS_H