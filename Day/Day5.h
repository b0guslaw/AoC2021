#ifndef DAY_5
#define DAY_5

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

namespace aoc {
namespace Day5 {

using Point = std::pair<int, int>;

using Point = std::pair<int, int>;
void fill_field1(const std::vector<std::string> &input, std::map<Point, int>& field) {
    int x1, y1, x2, y2;
    char c_discard; std::string s_discard;
    for(const auto& line : input) {
        std::stringstream iss(line);
        iss >> x1 >> c_discard >> y1 >> s_discard >> x2 >> c_discard >> y2;
        if (x1 == x2) {
            for (int y{std::min(y1, y2)}; y <= std::max(y1,y2); y++) {
                ++field[{x1, y}];
            }
        }

        if (y1 == y2) {
            for (int x{std::min(x1, x2)}; x <= std::max(x1,x2); x++) {
                ++field[{x, y1}];
            }
        }
    }
}

void fill_field2(const std::vector<std::string> &input, std::map<Point, int>& field) {
    int x1, y1, x2, y2;
    char c_discard; std::string s_discard;
	for(const auto& line : input) {
		std::stringstream iss(line);
		iss >> x1 >> c_discard >> y1 >> s_discard >> x2 >> c_discard >> y2;
		if (x1 == x2) {
			for (int y{std::min(y1, y2)}; y <= std::max(y1, y2); y++) {
				++field[{x1, y}];
			}
		} else if (y1 == y2) {
			for (int x{std::min(x1, x2)}; x <= std::max(x1, x2); x++) {
				++field[{x, y1}];
			}
		} else {
			int ux = 1, uy = 1;
			if (x1 > x2) { ux = -1; }
			if (y1 > y2) { uy = -1; }
			for (int _x{x1 - ux}, _y{y1 - uy}; _x != x2; ) {
				++field[{ _x += ux, _y += uy }];
			}
		}
	}
}

uint64_t Part1(const std::vector<std::string>& data) {
	std::map<Point, int> field;
	fill_field1(data, field);

	int overlaps = 0;
	for (auto& [point, value] : field) {
		if (value > 1) overlaps++;
	}
	return static_cast<uint64_t>(overlaps);
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::map<Point, int> field;
	fill_field2(data, field);

	int overlaps = 0;
	for (auto& [point, value] : field) {
		if (value > 1) overlaps++;
	}
	return static_cast<uint64_t>(overlaps);
}

}
}
#endif