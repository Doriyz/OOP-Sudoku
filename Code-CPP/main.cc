// main.cc

#include "sudoku.h"
#include <iostream>

int main() {
    Sudoku sudoku;
    std::string input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    
    // 解析字符串输入，得到Sudoku实例
    sudoku.parse(input);

    // 推理棋盘，得到各单元格候选值
    for (int i = 0; i < sudoku.GRID_SIZE; ++i) {
        for (int j = 0; j < sudoku.GRID_SIZE; ++j) {
            std::vector<int> candidates = sudoku.getInference(i, j);
            // 输出单元格的候选值
            std::cout << "Candidates for cell (" << i << ", " << j << "): ";
            for (int candidate : candidates) {
                std::cout << candidate << " ";
            }
            std::cout << std::endl;
        }
    }

    // 其他合理功能测试

    return 0;
}