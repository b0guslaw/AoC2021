#ifndef DAY_4
#define DAY_4

#include <vector>
#include <numeric>
#include <sstream>
#include <utility>
#include <set>

namespace aoc {
namespace Day4 {

using Board = std::vector<std::pair<int, bool>>;

std::vector<int> parse_line(const std::string& s) {
	int num;
	std::stringstream iss(s);

	std::vector<int> t;
	while(iss >> num) {
		if (iss.peek() == ',') iss.ignore();
		t.push_back(num);
	}
	return t;
}

Board parse_board_line(const std::string& s) {
	int num;
	std::stringstream iss(s);

	Board t;
	while(iss >> num) {
		t.push_back(std::make_pair(num, false));
	}
	return t;
}

void update(Board& board, int num) {
	for (auto& entry : board) {
		if (entry.first == num) {
			entry.second = true;
		}
	}
}

bool determine_win(const Board& board) {
	bool won = false;
	// Check Rows
	for (size_t i{0}; i < board.size(); i += 5) {
		if (i + 1 >= board.size()) break;
		won = board[i].second && board[i + 1].second && board[i + 2].second && board[i + 3].second && board[i + 4].second;
		if (won) {
			return won;
		}
	}
	//Check Columns
	for(size_t i{0}; i < 5; i++) {
		won = board[0 * 5 + i].second && board[1 * 5 + i].second && board[2 * 5 + i].second && board[3 * 5 + i].second && board[4 * 5 + i].second;
		if (won) {
			return won;
		}
	}
	return won;
}

uint64_t get_sum(const Board& board) {
	 uint64_t sum = 0;
	 for (auto& entry : board) {
		 if (!entry.second) {
			 sum += entry.first;
		 }
	 }
	 return sum;
}

uint64_t Part1(const std::vector<std::string>& data) {
	std::vector<int> draws = parse_line(data[0]);
	
	std::vector<Board> boards;

	for (size_t i{1}; i < data.size(); ++i) {
		boards.push_back(parse_board_line(data[i]));
	}

	bool no_winner = true;
	while(no_winner) {
		for (auto num : draws) {
			for (auto& board : boards) {
				update(board, num);
				if (determine_win(board)) {
					return num * get_sum(board);
				}
			}
		}
	}
	return 0;
}

uint64_t Part2(const std::vector<std::string>& data) {
	std::vector<int> draws = parse_line(data[0]);
	std::vector<Board> boards;

	for (size_t i{1}; i < data.size(); ++i) {
		boards.push_back(parse_board_line(data[i]));
	}

	for (auto draw : draws) {
		for (size_t i{0}; i < boards.size(); i++) {
		update(boards[i], draw);
		if (determine_win(boards[i])) {
			if (boards.size() > 1) {
				boards.erase(boards.begin() + i--);
			} else if (boards.size() == 1) {
				return draw * get_sum(boards[0]);
			}
		}
		}
	}
	return 0;
}

}
}
#endif