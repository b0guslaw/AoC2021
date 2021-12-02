#ifndef DAY_2
#define DAY_2

#include <vector>

namespace aoc {
namespace Day2 {

const std::string forward{"forward"}, up{"up"}, down{"down"};

int Part1(const std::vector<std::string>& data) {
	int horiz = 0, depth = 0;

	for (const auto& op : data) {
		int amount = 0;
		if (op.starts_with(forward)) {
			amount = std::stoi(op.substr(forward.size(), op.size()));
			horiz += amount;
		}
		if (op.starts_with(up)) {
			amount = std::stoi(op.substr(up.size(), op.size()));
			depth -= amount;
		}
		if (op.starts_with(down)) {
			amount = std::stoi(op.substr(down.size(), op.size()));
			depth += amount;
		}
	}
	return horiz * depth;
}

int Part2(const std::vector<std::string>& data) {
	int horiz = 0, depth = 0, aim = 0;

	for (const auto& op : data) {
		int amount = 0;
		if (op.starts_with(forward)) {
			amount = std::stoi(op.substr(forward.size(), op.size()));
			horiz += amount;
			depth += (aim * amount);
		}
		if (op.starts_with(up)) {
			amount = std::stoi(op.substr(up.size(), op.size()));
			aim -= amount;
		}
		if (op.starts_with(down)) {
			amount = std::stoi(op.substr(down.size(), op.size()));
			aim += amount;
		}
	}
	return horiz * depth;
}
}
}
#endif