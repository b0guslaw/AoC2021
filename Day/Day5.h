#ifndef DAY_5
#define DAY_5

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace aoc {
namespace Day5 {

struct Point {
	Point() : x{0}, y{0} {}
	Point(int x, int  y) : x{x}, y{y} {}
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

bool intersect(Segment& s1, Segment& s2) {
  if ((s1.x_min >= s2.x_min && s1.x_min <= s2.x_max) &&
      (s2.y_min >= s1.y_min && s2.y_min <= s1.y_max)) {
    return true;
  } else if ((s2.x_min >= s1.x_min && s2.x_min <= s1.x_max) &&
             (s1.y_min >= s2.y_min && s1.y_min <= s2.y_max)) {
    return true;
  }
  return false;
}

std::vector<int> parse_data(const std::vector<std::string> input) {
	std::vector<int> output;
	int x1, y1, x2, y2;
	for(auto line : input) {
		std::replace(line.begin(), line.end(), ',', ' ');
		std::replace(line.begin(), line.end(), '-', ' ');
		std::replace(line.begin(), line.end(), '>', ' ');

		std::stringstream iss(line);
		iss >> x1 >> y1 >> x2 >> y2;
		output.push_back(x1); output.push_back(y1);
		output.push_back(x2); output.push_back(y2);
	}
	return output;
}

uint64_t Part1(const std::vector<std::string>& data) {
	auto coordinates_raw = parse_data(data);
	std::vector<Segment> segments;
	for (size_t i{0}; i < coordinates_raw.size(); i += 4) {
		Point p1{i, i + 2};
		Point p2{i + 3, i + 4};
		segments.emplace_back(p1, p2);
	}

	int intersections = 0;
	for (Segment& s1 : segments) {
		for (Segment& s2 : segments) {
			if(s1 == s2) {
				continue;
			}

			if (s1.is_not_angled() && s2.is_not_angled()) {
				if (intersect(s1, s2)) {
					intersections++;
				}
			}
		}
	}
	return intersections;
}

uint64_t Part2(const std::vector<std::string>& data) {
	return data.size();
}

}
}
#endif