#ifndef DAY_6
#define DAY_6

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

namespace aoc {
namespace Day6 {

const int breeding_day = 6;
const int death_day = 0;

inline void load_data(std::array<uint64_t, 9>& fish, const std::vector<int>& data) {
	std::for_each(data.begin(), data.end(), [&](uint64_t day) {
		++fish[day];
	});
}

template<size_t T>
void simulate(std::array<uint64_t, T>& fish) {
	uint64_t new_fish = fish[death_day];
	std::rotate(fish.begin(), fish.begin() + 1, fish.end());
	fish[breeding_day] += new_fish;
};

template<size_t N, size_t T>
void run_simulation(std::array<uint64_t, T>& fish) {
	for (size_t i{0}; i < N; i++) {
		simulate(fish);
	}
}

inline uint64_t sum(std::array<uint64_t, 9> fish) {
	uint64_t sum = 0;
	for (auto& day : fish) {
		sum += day;
	}
	return sum;
}

uint64_t Part1(const std::vector<int>& data) {
	std::array<uint64_t, 9> fish{};
	load_data(fish, data);
	run_simulation<80>(fish);
	return sum(fish);
}

uint64_t Part2(const std::vector<int>& data) {
	std::array<uint64_t, 9> fish{};
	load_data(fish, data);
	run_simulation<256>(fish);
	return sum(fish);
}

}
}
#endif