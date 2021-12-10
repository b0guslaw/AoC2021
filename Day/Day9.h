#ifndef DAY_9
#define DAY_9

#include <vector>
#include <iostream>

namespace aoc {
namespace Day9 {

uint64_t Part1(std::vector<std::string>& data) {
	uint64_t total{0};
	int width{static_cast<int>(data[0].length())};
	int height{static_cast<int>(data.size())};

	const auto lowest = [&](const int row, const int col) {
		if (data[row][col] == '9') return false;
		if (data[row][col] == '0') return true;
		
		bool lowest = true;
		if ((row > 0 && data[row][col] >= data[row - 1][col]) ||
		   	(col > 0 && data[row][col] >= data[row][col - 1]) ||
		   	(row < height - 1 && data[row][col] >= data[row + 1][col]) ||
		   	(col < width  - 1 && data[row][col] >= data[row][col+ 1])) {
			   lowest = false;
		   }
		   return lowest;
	};

	for(int i{0}; i < width * height; ++i) {
		int x = i % width, y = i / width;
		if ((lowest(y, x))) {
			total += data[y][x] - 47;
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
