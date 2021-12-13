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
	std::string signal;

	for (auto& line : data) {
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

int decode(const std::vector<std::string> patterns, const std::vector<std::string>& numbers) {

	std::string result{};
	for (auto& n : numbers) {
		int sz = n.size();
		switch (sz) {
			case 2: result += '1'; break;
			case 3: result += '7'; break;
			case 4: result += '4'; break;
			case 7: result += '8'; break;
		}

		if (sz == 5) {
			if (std::all_of(patterns.at(0).begin(), patterns.at(0).end(), [&](const char& c) {
				return std::find(n.begin(), n.end(), c) != n.end();
			})) {
				result += '3';
			} else if (std::count_if(patterns[2].begin(), patterns[2].end(), [&](const char& c) {
				return std::find(n.begin(), n.end(), c) != n.end(); }) == 2) {
				result += '2';
			} else {
				result += '5';
			}
		} else if (sz == 6) {
			if (std::all_of(patterns[0].begin(), patterns[0].end(), [&](const char& c) { return std::find(n.begin(), n.end(), c) != n.end(); })) {
				if (std::count_if(patterns.at(2).begin(), patterns.at(2).end(), [&](const char& c) { return std::find(n.begin(), n.end(), c) != n.end(); }) == 3) {
					result += "0";
				} else {
					result += '9';
				}
			} else {
				result += '6';
			}
		}

	}
	return std::stoi(result);
}

uint64_t Part2(const std::vector<std::string>& data) {

	uint64_t total{0};
	for (auto& line : data) {
		std::vector<std::string> patterns, numbers;

		std::stringstream iss(line);
		std::string token;

		for(; iss >> token; patterns.emplace_back(token)) { if(token == "|") break; }
		std::sort(patterns.begin(), patterns.end(), [](const auto& lhs, const auto& rhs){ return lhs.length() < rhs.length(); });
		for(; iss >> token; numbers.emplace_back(token));

		total += decode(patterns, numbers);
	}

	return total;
}

}
}
#endif
