#include "Input.h"

#include <chrono>

#include "Day/Day1.h"
#include "Day/Day2.h"
#include "Day/Day3.h"
#include "Day/Day4.h"
#include "Day/Day5.h"
#include "Day/Day6.h"
#include "Day/Day7.h"
#include "Day/Day8.h"
#include "Day/Day9.h"
#include "Day/Day10.h"
#include "Day/Day11.h"

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

void Day6(std::vector<int> data) {
	auto [result1, elapsed1] = Runner(aoc::Day6::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day6::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day7(std::vector<int> data) {
	auto [result1, elapsed1] = Runner(aoc::Day7::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day7::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day8(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day8::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day8::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day9(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day9::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day9::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day10(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day10::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day10::Part2, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

void Day11(std::vector<std::string> data) {
	auto [result1, elapsed1] = Runner(aoc::Day11::Part1, data);
	auto [result2, elapsed2] = Runner(aoc::Day11::Part1, data);
	print(__func__, result1, elapsed1, result2, elapsed2);
}

int main() {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
	Day2(Input::GetStringData(dir + "Day2.txt"));
	Day3(Input::GetStringData(dir + "Day3.txt"));
	Day4(Input::GetEmptyNewLineData(dir + "Day4.txt"));
	Day5(Input::GetStringData(dir + "Day5.txt"));
	Day6(Input::GetData<int>(dir + "Day6.txt", ','));
	Day7(Input::GetData<int>(dir + "Day7.txt", ','));
	Day8(Input::GetStringData(dir + "Day8.txt"));
	Day9(Input::GetStringData(dir + "Day9.txt"));
	Day10(Input::GetStringData(dir + "Day10.txt"));
	Day11(Input::GetStringData(dir + "Day10.txt"));
}