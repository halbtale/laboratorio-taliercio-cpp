#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <array>

class Maze {
	int _current_position_x {};
	int _current_position_y {};

	std::vector<std::string> _map;
	std::array<int, 2> find(char c) const;
	std::array<int, 2> find_start() const;
	std::array<int, 2> find_exit() const;

	int _exit_x {};
	int _exit_y {};

public:
	explicit Maze(const std::string& file_path);
	
	bool is_wall(int x, int y) const;

	std::array<int, 2> get_current_position() const;
	void set_current_position(int x, int y);

	bool is_exit() const;
	
	class NotFoundException final : std::exception {};
	class InvalidMoveException final : std::exception {};
};

#endif