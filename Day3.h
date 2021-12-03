#ifndef DAY_3
#define DAY_3

#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>

namespace aoc {
namespace Day3 {
uint64_t Part1(const std::vector<std::string>& data) {
	std::string gamma;
	for(size_t i{0}; i < data[0].size(); ++i) {
		int one{0}, zero{0};

		for (size_t j{0}; j < data.size(); j++) {
			if (data[j][i] == '1') {
				++one;
			} else {
				++zero;
			}
		}

		if (one > zero) {
			gamma += "1";
		} else {
			gamma += "0";
		}
	}

	std::bitset<12> g_rate(gamma.c_str());
	auto e_rate = g_rate;
	e_rate.flip();
	return static_cast<uint64_t>(e_rate.to_ullong()) *
			static_cast<uint64_t>(g_rate.to_ullong());
}

void Update(std::vector<std::string>& data, int criteria /* 0 = oxygen, 1 = co2*/ ) {
	while(data.size() != 1) {
		if (data.size() == 1) return;
		for (size_t i{0}; i < data[0].size(); i++) {
			int one{0}, zero{0};
			char keep;
			for (auto& entry : data) {
				if (entry[i] == '1') { ++one;  }
				if (entry[i] == '0') { ++zero; }
			}

			if (criteria == 0) {
				if (one > zero || zero == one) {
					keep = '1';
				} else {
					keep = '0';
				}
			}

			if (criteria == 1) {
				if (one > zero || zero == one) {
					keep = '0';
				} else {
					keep = '1';
				}
			}

			data.erase(
				std::remove_if(data.begin(), data.end(), [=](const std::string& entry){
					return entry[i] != keep;
				}), data.end()
			);
		}
		return;
	}
}

uint64_t Part2(const std::vector<std::string>& data) {
	auto oxy_data = data;
	auto o2_data = data;

	Update(oxy_data, 0);
	Update(o2_data, 1);

	std::bitset<12> o2(oxy_data[0].c_str());
	std::bitset<12> co2(o2_data[0].c_str());
	return static_cast<uint64_t>(o2.to_ullong()) *
			static_cast<uint64_t>(co2.to_ullong());
}
}
}
#endif