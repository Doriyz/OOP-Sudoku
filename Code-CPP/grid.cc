
#include "grid.h"
#include <cmath>
#include <string>
#include <vector>



Grid::Grid(const std::string& input) {
    for (int i = 0; i < GRID_SIZE; i++) {
        std::vector<int> row;
        for (int j = 0; j < GRID_SIZE; j++) {
            int val = input[i * GRID_SIZE + j] - '0';
            row.push_back(val);

            std::cout << val << " ";
        }
        std::cout << std::endl;
        grid.push_back(row);
    }

}


Grid::Grid() {

}


Grid::~Grid() {
    // 析构函数
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

bool Grid::GetInference(){
    return BackTracking(grid);
}

bool Grid::BackTracking(std::vector<std::vector<int>>& grid) {

    for (int i = 0; i < grid.size(); i++) {        // 遍历行
        for (int j = 0; j < grid[0].size(); j++) { // 遍历列
            if (grid[i][j] != 0) continue;
            for (int k = 1; k <= 9; k++) {     // (i, j) 这个位置放k是否合适
                if (isValid(i, j, k, grid)) { 
                    grid[i][j] = k;                // 放置k
                    if (BackTracking(grid)) return true; // 如果找到合适一组立刻返回
                    grid[i][j] = 0;              // 回溯，撤销k
                }
            }
            return false;                           // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}

bool Grid::isValid(int row, int col, int val, std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
        if (grid[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
        if (grid[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}


void Grid::Print(){
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// successfully pass test
int main(){
    Grid grid("017903600000080000900000507072010430000402070064370250701000065000030000005601720");

    std::cout << std::endl << "the init grid" << std::endl;
    grid.Print();
    grid.GetInference();

    std::cout << std::endl << "the final grid" << std::endl;
    grid.Print();
    
    return 0; 
}