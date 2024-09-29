#include "sudoku.h"
#include <iostream>

// 构造函数：从字符串初始化数独
Sudoku::Sudoku(const std::string& input) {
    grid.Init(input);
}


// 数独推理函数：解数独
bool Sudoku::getInference() {
    // 在这里实现数独推理算法，填充数独格子
    // 返回值表示是否成功解出数独
    return true; // 假设总是能成功解出数独
}

// 拷贝构造函数
Sudoku::Sudoku(const Sudoku& other) : grid(other.grid) {}

// 赋值操作符重载
Sudoku& Sudoku::operator=(const Sudoku& other) {
    if (this != &other) {
        for(int i = 0; i < GRID_SIZE; ++i){
            for(int j = 0; j < GRID_SIZE; ++j){
                grid.SetNum(i, j , other.GetNum(i, j));
            }
        }
    }
    return *this;
}

// 析构函数
Sudoku::~Sudoku() {
   
}

// 序列化数独对象
std::string Sudoku::serialize() const {
    return grid.serialize();
}

// 反序列化数据为数独对象
void Sudoku::deserialize(const std::string& data) {
    grid.deserialize(data);
}

// 比较两个数独对象是否相等
bool Sudoku::operator==(const Sudoku& other) const {
    return grid == other.grid;
}

// 打印数独
void Sudoku::print() const {
    grid.print();
}

// 检查数独是否合法
bool Sudoku::isValid() const {
    return grid.isValid();
}





int Sudoku::GetNum(int row, int col){
    return grid.GetNum(row, col);
}




int main() {
    // 示例用法
    Sudoku sudoku("530070000600195000098000060800060003400803001700020006060000280000419005000080079");
    sudoku.print();

    if (sudoku.getInference()) {
        std::cout << "Sudoku solved successfully!" << std::endl;
        sudoku.print();
    } else {
        std::cout << "Failed to solve Sudoku." << std::endl;
    }

    return 0;
}