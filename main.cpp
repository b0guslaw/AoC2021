#include "Input.h"

#include <chrono>

#include "Day1.h"
#include "Day2.h"


const std::string dir{"PuzzleInput/"};

auto print = [](const std::string& name, const std::string& part1, const std::string& part2){
	std::cout << "\t~~~ " << name << " ~~~" << "\nPart 1: " << part1 << "\nPart 2: " << part2 << "\n\n";
};

void Day1(std::vector<int> data) {
	int part1, part2;
	{
		auto start = std::chrono::high_resolution_clock::now();
		part1 = aoc::Day1::Part1(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".1 Elapsed time " << t << "\n";
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		part2 = aoc::Day1::Part2(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".1 Elapsed time " << t << "\n";
	}
	print(__func__, std::to_string(part1), std::to_string(part2));
}

void Day2(std::vector<int> data) {
	int part1, part2;
	{
		auto start = std::chrono::high_resolution_clock::now();
		part1 = aoc::Day2::Part1(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".1 Elapsed time " << t << "\n";
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		part2 = aoc::Day2::Part2(data);
		auto end = std::chrono::high_resolution_clock::now();
		auto t = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << __func__ << ".1 Elapsed time " << t << "\n";
	}
	print(__func__, std::to_string(part1), std::to_string(part2));
}

int main(int argc, const char** argv) {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
	Day2(Input::GetData<int>(dir + "Day2.txt", '\n'));
}