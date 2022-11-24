#ifndef DAY_5
#define DAY_5

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <array>

namespace aoc {
namespace Day5 {

void fill_field1(const std::vector<std::string> &input, std::vector<int>& board) {
    int x1, y1, x2, y2;
    char c_discard; std::string s_discard;

	int max_size{0};
	std::vector<std::array<int, 4>> field;
    for(const auto& line : input) {
        std::stringstream iss(line);
        iss >> x1 >> c_discard >> y1 >> s_discard >> x2 >> c_discard >> y2;
		field.push_back({x1, y1, x2, y2});
		int temp_max = std::max({x1, y1, x2, y2});
		if (temp_max > max_size) { max_size = temp_max; }
	}

	board.resize(max_size * max_size);
	for (const auto& segment : field) {
		x1 = segment[0]; y1 = segment[1];
		x2 = segment[2]; y2 = segment[3];

		if (x1 == x2) {
            for (int y{std::min(y1, y2)}; y <= std::max(y1,y2); y++) {
                board[x1 + y * max_size]++;
            }
        }

        if (y1 == y2) {
            for (int x{std::min(x1, x2)}; x <= std::max(x1,x2); x++) {
                board[x + y1 * max_size]++;
            }
        }
	}
}

void fill_field2(const std::vector<std::string> &input, std::vector<int>& board) {
    int x1, y1, x2, y2;
    char c_discard; std::string s_discard;

	int max_size{0};
	std::vector<std::array<int, 4>> field;
    for(const auto& line : input) {
        std::stringstream iss(line);
        iss >> x1 >> c_discard >> y1 >> s_discard >> x2 >> c_discard >> y2;
		field.push_back({x1, y1, x2, y2});
		int temp_max = std::max({x1, y1, x2, y2});
		if (temp_max > max_size) { max_size = temp_max; }
	}

	++max_size;
	board.resize(max_size * max_size);
	for (const auto& segment : field) {
		x1 = segment[0]; y1 = segment[1];
		x2 = segment[2]; y2 = segment[3];

		if (x1 == x2) {
            for (int y{std::min(y1, y2)}; y <= std::max(y1,y2); y++) {
                board[x1 + y * max_size]++;
            }
        } else if (y1 == y2) {
            for (int x{std::min(x1, x2)}; x <= std::max(x1,x2); x++) {
                board[x + y1 * max_size]++;
            }
        } else {
			int _x = 1;
			int _y = 1;
			if (x1 > x2) { _x = -1; }
			if (y1 > y2) { _y = -1; }

			int src = std::min(x1, x2);
			int dst = std::max(x1, x2);

			for (int idx{0}; idx + src <= dst; ++idx) {
				++board[(x1 + idx * _x) + (y1 + idx * _y) * max_size];
			}
		}
	}
}

uint64_t Part1(const std::vector<std::string>& data) {
	std::vector<int> field;
	fill_field1(data, field);
	return static_cast<uint64_t>(
		std::accumulate(field.begin(), field.end(), 0, [](const int first, const int second) {
			return first + (second > 1);
		})
	);
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::vector<int> field;
	fill_field2(data, field);
	return static_cast<uint64_t>(
		std::accumulate(field.begin(), field.end(), 0, [](const int first, const int second) {
			return first + (second > 1);
		})
	);
}

}
}
#endif