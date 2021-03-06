#ifndef DAY_1
#define DAY_1

#include <vector>
#include <algorithm>

namespace aoc {
namespace Day1 {
uint64_t Part1(const std::vector<int>& data) {
	int last{data[0]};
	int sum = std::count_if(data.begin(), data.end(), [&](const int depth){
		bool res = depth > last;
		last = depth;
		return res;
	});
	return sum;
}

uint64_t Part2(const std::vector<int>& data) {
	int sum{0};
	for (size_t i{0}; i < data.size(); i++) {
		if (i + 3 < data.size() && data[i + 3] > data[i]) {
			++sum;
		}
	}
	return sum;
}
}
}
#endif