#include "Maze.h"
#include <fstream>
#include <iostream>
#include <array>

Maze::Maze(const std::string& file_path) {
	std::fstream fs;
	fs.open(file_path);
	
	std::string readLine;
	
	while (std::getline(fs, readLine)) {
		_map.push_back(readLine);
	}
	
	fs.close();

	const std::array<int, 2> start = find_start();

	set_current_position(start[0], start[1]);

	const std::array<int, 2> exit = find_exit();

	_exit_x = exit[0];
	_exit_y = exit[1];
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

std::array<int, 2> Maze::get_current_position() const {
	const std::array<int, 2> position = {_current_position_x, _current_position_y};
	return position;
}

void Maze::set_current_position(const int x, const int y) {
	if (is_wall(x, y)) throw InvalidMoveException();

	_current_position_x = x;
	_current_position_y = y;
}

std::array<int, 2> Maze::find_start() const {
	return find('S');
};

std::array<int, 2> Maze::find_exit() const {
	return find('E');
};

bool Maze::is_exit() const {
	return _current_position_x == _exit_x && _current_position_y == _exit_y;
}