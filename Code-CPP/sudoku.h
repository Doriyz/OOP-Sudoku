#ifndef SUDOKU_H
#define SUDOKU_H

#include "grid.h"
#include <string>

class Sudoku : public Grid {

private:
    Grid grid;

public:
    Sudoku(const std::string& input);   
    ~Sudoku(); 
    Sudoku Clone();
    std::string Serialize();
    bool Equals(Sudoku other);

    std::string parse();
    std::vector<int> getInference(int row, int col);
};

#endif