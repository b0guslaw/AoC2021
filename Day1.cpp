#include "Input.h"

void Part1(const std::string& path) {
    std::vector<int> data = Input::GetData<int>(path, '\n');
    int sum = 0;
    int last = data[0];
    for (int i = 1; i < data.size(); i++) {
        if (data[i] > last) {
            ++sum;
        }
        last = data[i];
    }
    std::cout << sum << "\n";
}

void Part2(const std::string& path) {
    std::vector<int> data = Input::GetData<int>(path, '\n');

    int sum = 0;
    int previousWindow = data[0] + data[1] + data[2];
    for (int i = 1; i < data.size() - 2; i++) {
        int newWindow = data[i] + data[i + 1] + data [i+2];
        if (newWindow > previousWindow) {
            ++sum;
        }
        previousWindow = newWindow;
    }
    std::cout << sum << "\n";
}

int main() {
    Part1("PuzzleInput/Day1.txt");
    Part2("PuzzleInput/Day1.txt");
}