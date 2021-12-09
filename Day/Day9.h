#ifndef DAY_9
#define DAY_9

#include <vector>
#include <iostream>

namespace aoc {
namespace Day9 {

uint64_t Part1(std::vector<std::string>& data) {

	std::vector<std::string> field;
	field.emplace_back(std::string(data[0].size() + 2, '9'));
	for (auto& line : data) {
		line.insert(0, 1 ,'9');
		line += '9';
		field.push_back(line);
	}
	field.emplace_back(std::string(data[0].size(), '9'));

	const auto lowest = [&](const int row, const int col) {
	return field[row-1][col] > field[row][col] && field[row+1][col] > field[row][col] &&
		   field[row][col+1] > field[row][col] && field[row][col-1] > field[row][col];
	};

	int total = 0;
	for (int row{1}; row < field.size() - 1; row++) {
		for (int col{1}; col < field[row].length() - 1; col++) {
			if (lowest(row, col)) {
				total += 1 + (field[row][col] - '0');
			}
		}
	}
	return total;
}

uint64_t Part2(const std::vector<std::string>& data) {
	auto _m = data;
	return 0;
}

}
}
#endif
