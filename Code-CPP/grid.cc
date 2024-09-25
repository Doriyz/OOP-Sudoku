#include "grid.h"

std::vector<int> Grid::getRow(int row) {
    return grid[row];
}

std::vector<int> Grid::getColumn(int col) {
    std::vector<int> column;
    for (int i = 0; i < GRID_SIZE; ++i) {
        column.push_back(grid[i][col]);
    }
    return column;
}

std::vector<int> Grid::getBox(int row, int col) {
    std::vector<int> box;
    int startRow = row / BOX_SIZE * BOX_SIZE;
    int startCol = col / BOX_SIZE * BOX_SIZE;
    for (int i = startRow; i < startRow + BOX_SIZE; ++i) {
        for (int j = startCol; j < startCol + BOX_SIZE; ++j) {
            box.push_back(grid[i][j]);
        }
    }
    return box;
}