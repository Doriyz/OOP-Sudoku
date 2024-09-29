#ifndef SUDOKU_H
#define SUDOKU_H

#include "grid.h"
#include <string>

class Sudoku : public Grid {

private:
    Grid grid;

public:
    Sudoku(const std::string& input); // 从字符串初始化数独
    // bool getInference(); // 解数独
    Sudoku(); // 构造函数
    void print();


    Sudoku(const Sudoku& other); // 拷贝构造函数
    Sudoku& operator=(const Sudoku& other); // 赋值操作符重载
    ~Sudoku(); // 析构函数
    std::string serialize() const; // 序列化
    bool operator==(const Sudoku& other) const; // 比较操作符重载
    bool isValid() const; // 检查数独是否合法

};

#endif