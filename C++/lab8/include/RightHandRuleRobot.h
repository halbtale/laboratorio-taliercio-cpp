#ifndef RIGHT_HAND_RULE_ROBOT_H
#define RIGHT_HAND_RULE_ROBOT_H

#include "Robot.h"
#include "Maze.h"

class RightHandRuleRobot : public Robot {
public:
    int _current_direction; // [0: up, 1: right, 2: down, 3: left]
    bool _found_wall;

    RightHandRuleRobot() : _current_direction(rand() % 4), _found_wall(false) {}

    void move(Maze& maze) override;
};

#endif