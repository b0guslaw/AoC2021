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

const std::array<std::string, 10> digits = {
	("abcefg"),
	("cf"),	
	("acdeg"),	
	("acdfg"),		
	("bcdf"),		
	("abdfg"),		
	("abdefg"),
	("acf"),
	("abcdefg"),
	("abcdfg")
};

//  dddd
// e    a
// e    a
//  ffff
// g    b
// g    b
//  cccc

// a = d
// b = e
// c = a
// d = f
// e = g
// f = b
// g = c

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

uint64_t Part2(const std::vector<std::string>& data) {
	bool counting = false;

	for (auto& d : mapped_digits) {
		std::sort(d.begin(), d.end());
	}

	auto find_index = [&](const std::string& signal){
		auto it = std::find(mapped_digits.begin(), mapped_digits.end(), signal);
		return std::distance(mapped_digits.begin(), it);
	};

	uint64_t total{0};
	for (auto& line : data) {
		std::vector<int> segment_order;
		std::vector<int> segments;

		std::string signal;
		std::stringstream iss(line);
		std::string res;

		while(iss >> signal) {

			if (signal == "|") {
				counting = true;
				continue;
			}
			
			if (counting) {
				res += find_index(signal);
				break;
			} else {
				std::sort(signal.begin(), signal.end());
				segment_order.push_back(find_index(signal));	
			}
		}

		counting = false;
	}

	return total;
}

}
}
#endif
