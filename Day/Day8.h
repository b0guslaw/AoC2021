#ifndef DAY_8
#define DAY_8

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <unordered_set>
#include <sstream>

namespace aoc {
namespace Day8 {

uint64_t Part1(const std::vector<std::string>& data) {
	bool counting = false;

	uint64_t total{0};
	for (auto& line : data) {
		std::string signal;
		std::stringstream iss(line);

		while(iss >> signal) {
			if (counting) {
				if (signal.size() == 2 || signal.size() == 3
					|| signal.size() == 4 || signal.size() == 7) {
						total++;
					}
			}

			if (signal == "|") {
				counting = true;
			}
		}

		counting = false;
	}

	return total;
}

uint64_t decode(const std::array<char, 7> &positions, const std::string& segment) {
	switch (segment.length()) {
		case 2: return 1;
		case 4: return 4;
		case 3: return 7;
		case 7: return 8;
		default: break;
	}

	return 0;
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::string token;
	for (auto& line : data) {

		std::array<char, 7> positions;

		auto connect = [&](char pos, char letter) { positions[letter - 'a'] = pos; };

		std::vector<std::string> lhs, rhs;
		std::stringstream iss(line);
		for(; iss >> token; lhs.emplace_back(token)) { if(token == "|") break; }
		for(; iss >> token; rhs.emplace_back(token));

		std::sort(lhs.begin(), lhs.end(), [](const auto& lhs, const auto& rhs){ return lhs.length() < rhs.length(); });

		const auto& one = lhs[0];
		const auto& four = lhs[1];
		const auto& seven = lhs[2];

		
	}

	return 0;
}

}
}
#endif
