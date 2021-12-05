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

struct Point {
	Point() : x{0}, y{0} {}
	Point(int x, int  y) : x{x}, y{y} {}
	Point(std::pair<int, int> pair) : x{pair.first}, y{pair.second} {}
	int x, y;

	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const {
		return !(*this == other);
	}
};

struct Segment {
	Segment(const Point& p1, const Point& p2) : p1{p1}, p2{p2} {
		x_min = std::min(p1.x, p2.x);
		x_max = std::max(p1.x, p2.x);
		y_min = std::min(p1.y, p2.y);
		y_max = std::max(p1.y, p2.y);
	}
	Point p1, p2;
	int x_min, x_max, y_min, y_max;

	bool operator==(const Segment& other) const {
		return p1 == other.p1 && p2 == other.p2;
	}

	bool operator!=(const Segment& other) const {
		return !(*this == other);
	}

	bool is_not_angled() const {
		return p1.x == p2.x || p1.y == p2.y;
	}
};

std::vector<int> parse_data(const std::vector<std::string> &input) {
	std::vector<int> output;
	int x1, y1, x2, y2;
	char c_discard; std::string s_discard;
	for(auto line : input) {
		std::stringstream iss(line);
		iss >> x1 >> c_discard >> y1 >> s_discard >> x2 >> c_discard >> y2;
		output.push_back(x1); output.push_back(y1);
		output.push_back(x2); output.push_back(y2);
	}
	return output;
}

uint64_t Part1(const std::vector<std::string>& data) {
	auto coordinates_raw = parse_data(data);
	std::vector<Segment> segments;

	std::map<std::pair<int, int>, int> field;
	for (int i{0}; i < coordinates_raw.size(); i += 4) {
		Point p1(std::make_pair(
			coordinates_raw.at(i), coordinates_raw.at(i + 1)
		));
		Point p2(std::make_pair(
			coordinates_raw.at(i + 2), coordinates_raw.at(i + 3)
		));

		segments.emplace_back(p1, p2);
	}

	for (const auto& s : segments) {

		// std::cout << s.p1.x << "," << s.p1.y << " -> " << s.p2.x << "," << s.p2.y << "\n";
		if (s.p1.x == s.p2.x) {
			for(int i{s.y_min}; i <= s.y_max; i++) {
				field[std::make_pair(s.p1.x, i)]++;
			}
		}
		if (s.p1.y == s.p2.y) {
			for(int i{s.x_min}; i <= s.x_max; i++) {
				field[std::make_pair(i, s.p1.y)]++;
			}
		}
	}

	int overlaps{0};
	for (auto const& p : field) {
		//std::cout << p.first.first << "," << p.first.second << " -> " << p.second << "\n";
		if (p.second > 1) {
			++overlaps;
		}
	}

	return static_cast<uint64_t>(overlaps);
}

uint64_t Part2(const std::vector<std::string>& data) {
	return data.size();
}

}
}
#endif