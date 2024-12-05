#include "Maze.h"
#include <iostream>
using namespace std;

int main() {
	Maze myMaze("../assets/map1.txt");
	
	cout << (myMaze.is_wall(1,1) ? "SI" : "NO") << "\n";
	
	array<int, 2> start = myMaze.find_start();
	cout << "(" << start[0] << " " << start[1] << ")" << "\n";
	
	array<int, 2> exit = myMaze.find_exit();
	cout << "(" << exit[0] << " " << exit[1] << ")" << "\n";
	
	return 0;
}