#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board {
public:
    Board();
    void printBoard();
    bool isSafe(int row, int col);
    bool solveNQueens(int col);
    
private:
    static const int SIZE = 8;
    std::vector<std::vector<char>> board;
};

#endif
