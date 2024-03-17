#include <iostream>
#include <vector>
#include <limits> 

#include "parser.hpp"
#include "player.hpp"

int main() {
    Parser parser;
    std::vector<std::vector<Cell>> maze = parser.parseMaze("./data/maze.txt");

    Player player(0, 3);

    while (true) {
        for (size_t i = 0; i < maze.size(); ++i) {
            for (size_t j = 0; j < maze[i].size(); ++j) {
                if (std::make_pair(i, j) == player.getPosition()) {
                    std::cout << 'P';
                } else {
                    std::cout << (maze[i][j].isWall ? '#' : '.');
                }
            }
            std::cout << std::endl;
        }

        char direction;
        std::cout << "Déplacez-vous avec les touches z (haut), s (bas), q (gauche), d (droite) ou l pour quitter : ";
        std::cin >> direction;

        if (direction == 'l' || direction == 'L') {
            std::cout << "Fin du jeu." << std::endl;
            break;
        } else {
            player.move(maze, direction);

            std::pair<size_t, size_t> playerPos = player.getPosition();
            std::cout << "Position du joueur : (" << playerPos.first << ", " << playerPos.second << ")" << std::endl;
        }

        std::cout << "\033[2J\033[H" << std::flush;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
