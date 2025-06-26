#include "Queen.h"

Queen::Queen() {}

void Queen::solveAndPrint() {
    if (board.solveNQueens(0)) {
        board.printBoard();
    } else {
        std::cout << "No solution exists for the 8 Queens Problem.\n";
    }
}
