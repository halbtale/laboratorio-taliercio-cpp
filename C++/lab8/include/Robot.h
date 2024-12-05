#ifndef ROBOT_H
#define ROBOT_H

class Robot {
protected:
	int _x;
	int _y;
	
public:
	virtual void move(const Maze& maze) = 0;
};

#endif