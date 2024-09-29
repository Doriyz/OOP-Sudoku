#include "sudoku.h"
#include <iostream>

// 构造函数：从字符串初始化数独
Sudoku::Sudoku(const std::string& input): Grid(input) {
}

Sudoku::Sudoku(): Grid() {
}

Sudoku::~Sudoku(){}

// // 数独推理函数：解数独
// bool Sudoku::getInference() {
//     return grid.GetInference(); 
// }

// //  打印数独结果
// void Sudoku::print(){
//     grid.Print();
// }
