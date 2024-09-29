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
    void Init(const std::string& input); // 使用数字串初始化
    std::vector<int> GetRow(int row); // 获取所在行的所有数字
    std::vector<int> GetColumn(int col); // 获取所在列的所有数字
    std::vector<int> GetBox(int row, int col); // 获取所在小方块的所有数字

    void SetNum(int row, int col, int num);
    int GetNum(int row, int col);
};

#endif