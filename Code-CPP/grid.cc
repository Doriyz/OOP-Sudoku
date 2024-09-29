
#include "grid.h"
#include <cmath>
#include <string>

Grid::Grid() {
}

Grid::~Grid() {
    // 析构函数
}

void Grid::Init(const std::string& input) {
    for (int i = 0; i < GRID_SIZE; i++) {
        std::vector<int> row;
        for (int j = 0; j < GRID_SIZE; j++) {
            int val = input[i * GRID_SIZE + j] - '0';
            row.push_back(val);
        }
        grid.push_back(row);
    }
}


std::vector<int> Grid::GetRow(int row) {
    return grid[row];
}

std::vector<int> Grid::GetColumn(int col) {
    std::vector<int> column;
    for (int i = 0; i < GRID_SIZE; i++) {
        column.push_back(grid[i][col]);
    }
    return column;
}

std::vector<int> Grid::GetBox(int row, int col) {
    std::vector<int> box;
    int startRow = (row / BOX_SIZE) * BOX_SIZE;
    int startCol = (col / BOX_SIZE) * BOX_SIZE;
    
    for (int i = startRow; i < startRow + BOX_SIZE; i++) {
        for (int j = startCol; j < startCol + BOX_SIZE; j++) {
            box.push_back(grid[i][j]);
        }
    }
    return box;
}


void Grid::SetNum(int row, int col, int num){
    grid[row][col] = num;
}

int Grid::GetNum(int row, int col){
    return grid[row][col];
}
