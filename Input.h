#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

namespace Input
{
	template<typename T>
	std::vector<T> GetData(const std::string& path, char delim = ' ') {
		std::vector<T> data;
		try {
			std::ifstream infile(path);
			std::string line;
			while(std::getline(infile, line, delim)) {
				T element;
				std::stringstream input(line);
				while(input >> element)
					data.push_back(element);
			}
		} catch (...) {
			std::cout << "An error occured!\n";
		}
		return data;
	}

	std::vector<std::string> GetEmptyNewLineData(const std::string& path) {
		std::ifstream infile(path);
		std::string temp;
		std::vector<std::string> data;
		for (std::string line; std::getline(infile, line); ) {
			if (line.empty()) {
				data.push_back(temp);
				temp.clear();
			}
			if (infile.eof()) {
				temp += line;
				data.push_back(temp);
			}
			temp += line;
			temp += " ";
		}
		return data;
	}

	std::vector<std::string> GetStringData(const std::string& path){
		std::vector<std::string> data;
		std::ifstream infile(path);
		for(std::string line; std::getline(infile, line); ) {
			data.push_back(line);
		}
		return data;
	}
};

#endif