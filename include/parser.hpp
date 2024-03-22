#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "player.hpp"

struct Cell {
    bool isWall;
    // isWall est public ici, on peut donc depuis l'exterieur décider que isWall = false
    // ce qui n'est pas forcément désirable
};

class Parser {
public:
    std::vector<std::vector<Cell>> parseMaze(const std::string& filename);
};

#endif // PARSER_HPPZZ