#include "../include/player.hpp"

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
        // On aimerait bien donner un nom un peu descriptif à cette condition pour la comprendre encore plus facilement
        // ou alors la split en 2 par exmeple if (is_in_maze(newRow, newCol) && !maze[newRow][newCol].isWall)
        // A priori sa place est soit dans le conteneur, qui est ici un vecteur (d'où le fait qu'on préfère souvent encapsuler dans des classes)
        // par exemple une classe Maze contenant le vector<Cell> aurait permi une syntaxe comme
        // if (maze.contains(newRow, newCol) and !maze.cells().get(newRow).get(newCol).isWall).

        // La logique et la gestion des erreurs peut etre encapsulée derrière la méthode et le code appelant devient encore plus clair.
        // Vous pouvez très bien créer une fonction et lui passer le vecteur is_in_vector(coord_x, coord_y, vector), cela revient
        // au même simplement cela permet d'organiser le code assez simplement et efficacement.

        // Une autre facon de le voir est de donner la responsabilité aux Cells.
        // Donc avoir des methodes cell.up(), right(), down(), left() qui renvoient soit une cell soit null si elles sont au bord (ou elle même en fonction de votre logique)
        // Cela ouvre des portes à de potentiels algorithmes récursifs pour se déplacer/faire des calculs dans le graph.
        position.first = newRow;
        position.second = newCol;
        std::cout << "Le joueur s'est déplacé avec succès." << std::endl;
    } else {
        std::cout << "Impossible de se déplacer dans cette direction." << std::endl;
    }
}
