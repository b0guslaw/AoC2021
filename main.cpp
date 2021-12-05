#include "Input.h"

#include <chrono>

#include "Day/Day1.h"
#include "Day/Day2.h"
#include "Day/Day3.h"
#include "Day/Day4.h"
#include "Day/Day5.h"

const std::string dir{"PuzzleInput/"};

auto print = [](const std::string& name, const uint64_t part1, double elapsed1, const uint64_t part2, double elapsed2){
	std::cout << "\t~~~ " << name << " ~~~"
				<< "\nPart 1: " << part1 << " elapsed time " <<	elapsed1 << "us"
				<< "\nPart 2: " << part2 << " elapsed time " <<	elapsed2 << "us\n\n";
};

template<typename F, typename I>
std::tuple<uint64_t, double> Runner(F func, std::vector<I> input) {
		auto start = std::chrono::high_resolution_clock::now();
		uint64_t result = func(input);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		return std::make_tuple(result, elapsed);
}

void Day1(std::vector<int> data) {
	auto [result1, elapsed1] = Runner(aoc::Day1::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day1::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day2(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day2::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day2::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day3(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day3::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day3::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day4(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day4::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day4::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day5(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day5::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day5::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day6(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day5::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day5::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

int main() {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
	Day2(Input::GetStringData(dir + "Day2.txt"));
	Day3(Input::GetStringData(dir + "Day3.txt"));
	Day4(Input::GetEmptyNewLineData(dir + "Day4.txt"));
	Day5(Input::GetStringData(dir + "Day5.txt"));
	Day5(Input::GetStringData(dir + "Day6.txt"));
}