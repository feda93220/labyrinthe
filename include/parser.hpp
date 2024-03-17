#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "player.hpp"

struct Cell {
    bool isWall;
};

class Parser {
public:
    std::vector<std::vector<Cell>> parseMaze(const std::string& filename);
};

#endif // PARSER_HPP