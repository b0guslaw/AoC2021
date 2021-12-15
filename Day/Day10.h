#ifndef DAY_10
#define DAY_10

#include <vector>
#include <string>
#include <stack>
#include <map>

namespace aoc {
namespace Day10 {

auto syntax_check(const std::string line) {
	uint64_t part1_score{0}, part2_score{0};
	std::map<char, int> scores = {{')',3}, {']',57}, {'}',1197}, {'>',25137}};
	std::vector<char> stack;
	for (auto& c : line) {
		switch (c) {
			case '(':
			case '{':
			case '[':
			case '<':
				stack.push_back(c);
				continue;
			case ')':
				if (stack.back() != '(') { part1_score += scores[c]; }
				break;
			case '}':
				if (stack.back() != '{') { part1_score += scores[c]; }
				break;
			case ']':
				if (stack.back() != '[') { part1_score += scores[c]; }
				break;
			case '>':
				if (stack.back() != '<') { part1_score += scores[c]; }
				break;
		}

		stack.pop_back();
	}
	while(!stack.empty()) {
		part2_score = part2_score * 5 + std::string("([{<").find(stack.back()) + 1;
		stack.pop_back();
	}
	return std::make_pair(part1_score, part2_score);
}

uint64_t Part1(const std::vector<std::string>& data) {
	uint64_t sum{0};
	for (auto& line : data) {
		auto [result, ignore] = syntax_check(line);
		sum += result;
	}
	return sum;
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::vector<uint64_t> sums;
	for (auto& line : data) {
		auto [ignore, result] = syntax_check(line);
		if (ignore == 0) {
			sums.push_back(result);
		}
	}
	std::sort(sums.begin(), sums.end());
	return sums[sums.size() / 2];
}
}
}
#endif