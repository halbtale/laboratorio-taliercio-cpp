#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <array>

class Maze {
	std::vector<std::string> _map;
	std::array<int, 2> find(char c) const;
public:
	
	Maze(const std::string file_path);
	
	bool is_wall(const int x, const int y) const;
	
	std::array<int, 2> find_start() const;
	std::array<int, 2> find_exit() const;
	
	class NotFoundException {};
};

#endif