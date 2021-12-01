#include "Day1.h"

#include "Input.h"

const std::string dir{"PuzzleInput/"};

auto print = [](const std::string& name, const std::string& part1, const std::string& part2){
	std::cout << "\t~~~ " << name << " ~~~" << "\nPart 1: " << part1 << "\nPart 2: " << part2 << "\n\n";
};

void Day1(std::vector<int> data) {
	int part1 = aoc::Day1::Part1(data);
	int part2 = aoc::Day1::Part2(data);

	print(__func__, std::to_string(part1), std::to_string(part2));
}

int main(int argc, const char** argv) {
	Day1(Input::GetData<int>(dir + "Day1.txt", '\n'));
}