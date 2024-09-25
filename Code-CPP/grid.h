#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:
    std::vector<std::vector<int>> grid;

public:
    const int BOX_SIZE = 3;
    const int GRID_SIZE = 9;

public:
    Grid();
    ~Grid();
    std::vector<int> getRow(int row);
    std::vector<int> getColumn(int col);
    std::vector<int> getBox(int row, int col);
};

#endif