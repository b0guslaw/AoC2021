#ifndef DAY_4
#define DAY_4

#include <vector>
#include <array>
#include <sstream>
#include <tuple>

namespace aoc {
namespace Day4 {

using Board = std::array<std::vector<std::tuple<int, bool>>, 5>;

std::vector<int> parse_line(const std::string& s) {
	std::cout << "Parsing Line...\n";
	int num;
	std::stringstream iss(s);

	std::vector<int> t;
	while(iss >> num) {
		t.push_back(num);
	}
	std::cout << "Parsing Line done!\n";
	return t;
}

Board construct_board(const std::string& s) {
	
}

std::vector<std::tuple<int, bool>> parse_board_line(const std::string& s) {
	std::cout << "Parsing Board line...\n";
	int num;
	std::stringstream iss(s);
	std::vector<std::tuple<int, bool>> t;
	while(iss >> num) {
		t.push_back(std::make_tuple(num, false));
	}
	std::cout << "Parsing board line done!\n";
	return t;
}

uint64_t Part1(const std::vector<std::string>& data) {
	std::vector<int> draws = parse_line(data[0]);
	return 0;
}

uint64_t Part2(const std::vector<std::string>& data) {
	return 0;
}
}
}
#endif