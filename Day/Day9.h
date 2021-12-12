#ifndef DAY_9
#define DAY_9

#include <vector>
#include <iostream>
#include <array>
#include <algorithm>

namespace aoc {
namespace Day9 {

uint64_t Part1(const std::vector<std::string>& data) {
	uint64_t total{0};
	
	const int width{static_cast<int>(data.front().length())};
	const int height{static_cast<int>(data.size())};

	const auto is_valid = [&](unsigned int x, unsigned int y){
		auto isvalid =  x <= height - 1 && y <= width - 1;
		return isvalid;
	};

	for (unsigned x{0}; x < height; x++) {
		for (unsigned int y{0}; y < width; y++) {
			
			static constexpr char max{'9'};

			if (data[x][y] == max) {
				continue;
			}

			const auto neighbours = std::array<char, 4> {
					is_valid(x - 1, y) ? data[x - 1][y] : max,
					is_valid(x + 1, y) ? data[x + 1][y] : max,
					is_valid(x, y + 1) ? data[x][y + 1] : max,
					is_valid(x, y - 1) ? data[x][y - 1] : max
			};

			const auto minimum = std::all_of(neighbours.begin(), neighbours.end(), [&](const char neighbour) {
				 return neighbour > data.at(x).at(y);;
			});

			total += static_cast<int>(data.at(x).at(y) - 47) * minimum;
		}
	}
	return total;
}

uint64_t flood_fill(std::vector<std::string>& field, unsigned x, unsigned int y) {
	const int width{static_cast<int>(field.front().length()) - 1};
	const int height{static_cast<int>(field.size()) - 1};

	uint64_t size{1};
	static constexpr char max{'9'};
	field[x][y] = max;

	static constexpr std::array<std::array<int, 2>, 4> directions = {{
		{1,0},
		{-1,0},
		{0,1},
		{0,-1}
	}};

	const auto is_valid = [&](unsigned int x, unsigned int y){
		auto isvalid = x <= height && y <= width && field[x][y] < max;
		return isvalid;
	};

	for (const auto& dir : directions) {
		if (is_valid(x + dir[0], y + dir[1])) {
			size += flood_fill(field, x + dir[0], y + dir[1]);
		}
	}

	return size;
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::vector<uint64_t> basin_sizes;
	auto field = data;

	const int width{static_cast<int>(field.front().length())};
	const int height{static_cast<int>(field.size())};
	
	for(int x{0}; x < height; x++) {
		for (int y{0}; y < width; y++) {
			if (field[x][y] < '9') {
				basin_sizes.push_back(
					flood_fill(field, x, y)
				);
			}
		}
	}

	std::sort(basin_sizes.begin(), basin_sizes.end(), std::greater<int>{});
	return basin_sizes[0] * basin_sizes[1] * basin_sizes[2];
}

}
}
#endif
