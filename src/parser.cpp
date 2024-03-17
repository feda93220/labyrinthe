#include "parser.hpp"
#include "player.hpp"

#include <fstream>

std::vector<std::vector<Cell>> Parser::parseMaze(const std::string& filename) {
    std::vector<std::vector<Cell>> maze;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        return maze;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<Cell> row;
        for (char c : line) {
            Cell cell;
            if (c == '#') {
                cell.isWall = true;
            } else if (c == '.') {
                cell.isWall = false;
            } else {
                std::cout << "Caractère inconnu trouvé dans le labyrinthe." << std::endl;
                cell.isWall = false;
            }
            row.push_back(cell);
        }
        maze.push_back(row);
    }

    file.close();

    return maze;
}
