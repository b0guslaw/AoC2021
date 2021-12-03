#ifndef DAY_2
#define DAY_2

#include <vector>

namespace aoc {
namespace Day2 {

const std::string forward{"forward"}, up{"up"}, down{"down"};

uint64_t Part1(const std::vector<std::string>& data) {
	uint64_t horiz{0}, depth{0};

	for (const auto& op : data) {
		int amount = 0;
		if (op[0] == 'f') {
			amount = static_cast<int>(op[forward.size() + 1]) - '0';
			horiz += amount;
		}
		if (op[0] == 'u') {
			amount = static_cast<int>(op[up.size() + 1]) - '0';
			depth -= amount;
		}
		if (op[0] == 'd') {
			amount = static_cast<int>(op[down.size() + 1]) - '0';
			depth += amount;
		}
	}
	return horiz * depth;
}

uint64_t Part2(const std::vector<std::string>& data) {
	uint64_t horiz{0}, depth{0}, aim{0};

	for (const auto& op : data) {
		int amount = 0;
		if (op[0] == 'f') {
			amount = static_cast<int>(op[forward.size() + 1]) - '0';
			horiz += amount;
			depth += (aim * amount);
		}
		if (op[0] == 'u') {
			amount = static_cast<int>(op[up.size() + 1]) - '0';
			aim -= amount;
		}
		if (op[0] == 'd') {
			amount = static_cast<int>(op[down.size() + 1]) - '0';
			aim += amount;
		}
	}
	return horiz * depth;
}
}
}
#endif