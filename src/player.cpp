#include "player.hpp"

void Player::move(const std::vector<std::vector<Cell>>& maze, char direction) {
    size_t newRow = position.first;
    size_t newCol = position.second;

    switch(direction) {
        case 'z':
            newRow--;
            break;
        case 's':
            newRow++;
            break;
        case 'q':
            newCol--;
            break;
        case 'd':
            newCol++;
            break;
        default:
            return;
    }

    if (newRow < maze.size() && newCol < maze[newRow].size() && !maze[newRow][newCol].isWall)  {
        
        position.first = newRow;
        position.second = newCol;
        std::cout << "Le joueur s'est déplacé avec succès." << std::endl;
    } else {
        std::cout << "Impossible de se déplacer dans cette direction." << std::endl;
    }
}
