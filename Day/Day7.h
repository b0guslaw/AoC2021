#ifndef DAY_7
#define DAY_7

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <functional>

namespace aoc {
namespace Day7 {

uint64_t Part1(const std::vector<int>& data) {
	auto crabs = data;
	auto pivot = crabs.begin() + crabs.size() / 2;
	std::nth_element(crabs.begin(), pivot, crabs.end(), std::less{});
	return std::accumulate(crabs.begin(), crabs.end(), 0ULL, [&](const int& sum, const int& crab) {
		return sum + std::abs(crab - static_cast<int64_t>(*pivot));
	});
}

uint64_t Part2(const std::vector<int>& data) {
	auto crabs = data;
	auto pivot = crabs.begin() + crabs.size() / 2;
	std::nth_element(crabs.begin(), pivot, crabs.end(), std::less{});
	int64_t avg = std::accumulate(crabs.begin(), crabs.end(), 0ULL) / crabs.size();
	if (avg < *pivot) { avg++; }
	return std::accumulate(crabs.begin(), crabs.end(), 0ULL, [&](const int& sum, const int& crab) {
		int64_t d = std::abs(crab - avg);
		return sum + ((d * (d + 1)) / 2);
	});
}

}
}
#endif
