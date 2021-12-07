#ifndef DAY_7
#define DAY_7

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

namespace aoc {
namespace Day7 {

uint64_t Part1(const std::vector<int>& data) {
	auto crabs = data;
	std::sort(crabs.begin(), crabs.end());
	int pivot = crabs[crabs.size() / 2];
	return std::accumulate(crabs.begin(), crabs.end(), 0ULL, [&](const int& sum, const int& crab) {
		return sum + std::abs(crab - pivot);
	});
}

uint64_t Part2(const std::vector<int>& data) {
	auto [min, max] = std::minmax_element(data.begin(), data.end());

	int closest = std::numeric_limits<int>::max();
	for (int i = *min; i <= *max; i++) {
		int totalfuel = 0;
		for (auto& crab : data){
			totalfuel += std::abs(crab - i) * (std::abs(crab - i) + 1) / 2;
		}

		if (totalfuel < closest) {
			closest = totalfuel;
		}
	}
	return closest;
}

}
}
#endif