#include "Input.h"

#include <chrono>
#include <variant>

#include "Day1.h"
#include "Day2.h"


const std::string dir{"PuzzleInput/"};

auto print = [](const std::string& name, const std::string& part1, double elapsed1, const std::string& part2, double elapsed2){
	std::cout << "\t~~~ " << name << " ~~~"
				<< "\nPart 1: " << part1 << " elapsed time " <<	elapsed1 << "us"
				<< "\nPart 2: " << part2 << " elapsed time " <<	elapsed2 << "us\n\n";
};

template<typename F, typename I>
std::tuple<std::string, double> Runner(F func, std::vector<I> input) {
		auto start = std::chrono::high_resolution_clock::now();
		std::variant<std::string, int> result = func(input);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		try {
			return std::make_tuple(std::get<std::string>(result), elapsed);
		} catch (const std::bad_variant_access& ex) {
			return std::make_tuple(std::to_string(std::get<int>(result)), elapsed);
		}
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

int main() {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
	Day2(Input::GetStringData(dir + "Day2.txt"));
}