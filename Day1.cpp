#include "Input.h"

void Part1(const std::string& path) {
    std::vector<int> data = Input::GetData<int>(path, '\n');
    int last = data[0];
    int sum = std::count_if(data.begin(), data.end(), [&](const int depth){
        int res = depth > last;
        last = depth;
        return res;
    });

    std::cout << sum << "\n";
}

void Part2(const std::string& path) {
    std::vector<int> data = Input::GetData<int>(path, '\n');
    int sum = 0;

    for (int i = 0; i < data.size(); i++) {
        if (data[i + 3] > data[i]) {
            ++sum;
        }
    }
    std::cout << sum << "\n";
}

int main() {
    Part1("PuzzleInput/Day1.txt");
    Part2("PuzzleInput/Day1.txt");
}