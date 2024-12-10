#include "Maze.h"
#include <iostream>
#include <RandomRobot.h>
using namespace std;

int main() {
	Maze myMaze("../assets/map1.txt");

	RandomRobot randomRobot {};

	int randomMoveCount = 0;

	while (!myMaze.is_exit()) {
		randomRobot.move(myMaze);
		cout << "Position: (" << myMaze.get_current_position()[0] << ", " << myMaze.get_current_position()[1] << ")" << endl;
		randomMoveCount++;
	}

	cout << "Random Robot took " << randomMoveCount << " moves to exit the maze." << endl;

	
	return 0;
}