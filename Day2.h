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
			amount = static_cast<int>(op[forward.size() + 1] - 48);
			horiz += amount;
		}
		if (op.starts_with(up)) {
			amount = static_cast<int>(op[up.size() + 1] - 48);
			depth -= amount;
		}
		if (op.starts_with(down)) {
			amount = static_cast<int>(op[down.size() + 1] - 48);
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
			amount = static_cast<int>(op[forward.size() + 1] - 48);
			horiz += amount;
			depth += (aim * amount);
		}
		if (op.starts_with(up)) {
			amount = static_cast<int>(op[up.size() + 1] - 48);
			aim -= amount;
		}
		if (op.starts_with(down)) {
			amount = static_cast<int>(op[down.size() + 1] - 48);
			aim += amount;
		}
	}
	return horiz * depth;
}
}
}
#endif