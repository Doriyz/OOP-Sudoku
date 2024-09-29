#include "grid.h"
#include "sudoku.h"
#include <iostream>

void test(const std::string& input){
    std::cout << "the input is:" << input << std::endl;
}

int main() {
    std::cout << "the input is:" << std::endl;
    std::string input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    

    Sudoku sudoku(input);
    // sudoku.Print();

    // if(sudoku.GetInference()){
        
    //     std::cout << "the complete grid is:" << std::endl;
    //     sudoku.Print();
    // }



    return 0;
}




// solution of test
// 4 1 7 9 5 3 6 8 2
// 2 5 6 1 8 7 9 4 3
// 9 8 3 2 4 6 5 1 7
// 8 7 2 5 1 9 4 3 6
// 5 3 9 4 6 2 8 7 1
// 1 6 4 3 7 8 2 5 9
// 7 9 1 8 2 4 3 6 5
// 6 2 8 7 3 5 1 9 4
// 3 4 5 6 9 1 7 2 8