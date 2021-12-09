#ifndef DAY_9
#define DAY_9

#include <vector>
#include <iostream>

namespace aoc {
namespace Day9 {

uint64_t Part1(const std::vector<std::string>& data) {

	int total = 0;

	auto lowest = [&](const int x, const int y) {
		if (data[x][y] == '0') { return true; }
		if (data[x][y] == '9') { return false; }
		int tocheck = data[x][y];
		if (x == 0) {
			if (y == 0) { return data[x][y+1] > tocheck && data[x+1][y] > tocheck; }
			if (y == data[0].size() - 1) { return data[x][y-1] > tocheck && data[x+1][y] > tocheck; }
			return data[x][y-1] > tocheck && data[x][y+1] > tocheck && data[x+1][y];
		}

		if (x == data.size() - 1) {
			if (y == 0) { return data[x][y+1] > tocheck && data[x-1][y] > tocheck; }
			if (y == data[0].size() - 1) { return data[x][y-1] > tocheck && data[x-1][y] > tocheck; }
			return data[x][y-1] > tocheck && data[x][y+1] > tocheck && data[x-1][y] > tocheck;
		}

		return data[x - 1][y] > tocheck && data[x+1][y] > tocheck
				&& data[x][y-1] > tocheck && data[x][y+1] > tocheck;
	};

	for (int row{0}; row < data.size(); row++) {
		for (int col{0}; col < data[0].size(); col++) {
			if (lowest(row, col)) {
				total += (data[row][col] - '0') + 1;
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
