#include <RightHandRuleRobot.h>

void RightHandRuleRobot::move(Maze& maze) {
    const std::array<int, 2> current_position = maze.get_current_position();
    bool is_valid_move = false;

    while (!is_valid_move) {
        const int direction = (maze.get_current_position()[0] + maze.get_current_position()[1]) % 4; // ADD LOGIC
        try {
            switch (direction) {
                case 0:
                    maze.set_current_position(current_position[0], current_position[1] - 1);
                break;
                case 1:
                    maze.set_current_position(current_position[0] + 1, current_position[1]);
                break;
                case 2:
                    maze.set_current_position(current_position[0], current_position[1] + 1);
                break;
                case 3:
                    maze.set_current_position(current_position[0] - 1, current_position[1]);
                break;
                default:
                    break;
            }
            is_valid_move = true;
        }catch (Maze::InvalidMoveException& e) {}
    }
}