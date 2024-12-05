#include "Maze.h"
#include <fstream>
#include <iostream>
#include <array>

Maze::Maze(const std::string file_path) {
	std::fstream fs;
	fs.open(file_path);
	
	std::string readLine;
	
	while (std::getline(fs, readLine)) {
		_map.push_back(readLine);
	}
	
	fs.close();
}

bool Maze::is_wall(const int x, const int y) const {
	if (x < 0 || y < 0 || y >= _map.size()) return true;
	
	const std::string& current_row = _map.at(y);
	
	if (x >= current_row.size()) return true;
	
	return current_row.at(x) == '*';
}

std::array<int, 2> Maze::find(char c) const {
	for (int y = 0; y<_map.size(); y++) {
		const std::string& current_row = _map.at(y);
		
		for (int x = 0; x<current_row.size(); x++) {
			if (current_row.at(x) == c) {
				std::array<int, 2> position = {x, y};
				return position;
			}
		}
	}
	throw NotFoundException();
}

std::array<int, 2> Maze::find_start() const {
	return find('S');
};

std::array<int, 2> Maze::find_exit() const {
	return find('E');
};