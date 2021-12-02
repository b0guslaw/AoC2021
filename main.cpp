#include "Input.h"

#include <chrono>

#include "Day1.h"
#include "Day2.h"


const std::string dir{"PuzzleInput/"};

auto print = [](const std::string& name, const std::string& part1, double elapsed1, const std::string& part2, double elapsed2){
	std::cout << "\t~~~ " << name << " ~~~"
				<< "\nPart 1: " << part1 << " elapsed time " <<	elapsed1 
				<< "\nPart 2: " << part2 << " elapsed time " <<	elapsed2 << "\n\n";
};

template<typename T>
std::tuple<std::string, double> Runner(auto func, std::vector<T> input) {
		auto start = std::chrono::high_resolution_clock::now();
		T result = func(input);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		return std::make_tuple(std::to_string(result), elapsed);
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

int main(int argc, const char** argv) {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
	Day2(Input::GetStringData(dir + "Day2.txt"));
}