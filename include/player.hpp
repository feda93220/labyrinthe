#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "parser.hpp"

struct Cell;

class Player {
private:
    std::pair<size_t, size_t> position;

public:
    Player(size_t row, size_t col) : position(row, col) {}

    std::pair<size_t, size_t> getPosition() const {
        return position;
    }

    void move(const std::vector<std::vector<Cell>>& maze, char direction);
};

#endif // PLAYER_HPP