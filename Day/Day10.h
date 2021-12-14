#ifndef DAY_10
#define DAY_10

#include <vector>
#include <string>
#include <stack>
#include <map>

namespace aoc {
namespace Day10 {

uint64_t Part1(const std::vector<std::string>& data) {
    uint64_t sum{0};
    const std::map<char, int> scores = {{')',3}, {']',57}, {'}',1197}, {'>',25137}};
    const std::map<char, char> pairs = {{'(',')'}, {'[',']'}, {'{','}'}, {'<','>'}};
    for (const auto& line : data) {
        std::stack<char> stack;
        for (auto& c : line) {
            if(c == '(' || c == '[' || c == '{' || c == '<') {
                stack.push(pairs.at(c));
            } else {
                if (c != stack.top()) {
                    sum += scores.at(c);
                    break;
                }
                stack.pop();
            }
        }
    }
    return sum;
}

uint64_t Part2(const std::vector<std::string>& data) {
	uint64_t sum{0};
    std::vector<std::string> incomplete;
    const std::map<char, char> pairs = {{'(',')'}, {'[',']'}, {'{','}'}, {'<','>'}};
    for (const auto& line : data) {
        std::stack<char> stack;
        for (auto& c : line) {
            if(c == '(' || c == '[' || c == '{' || c == '<') {
                stack.push(pairs.at(c));
            } else {
                if (c != stack.top()) {
                    break;
                }
                stack.pop();
            }
        }
        incomplete.push_back(line);
    }
    return sum;
}
}
}
#endif