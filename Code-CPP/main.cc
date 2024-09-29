// main.cc

#include "sudoku.h"
#include <iostream>

int main() {
    
    std::string input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    
    Sudoku sudoku(input);

    if(sudoku.getInference()){
        std::cout << "Done." << std::endl;
        std::cout << "the complete grid is:" << std::endl;
        sudoku.print();
    }

    return 0;
}