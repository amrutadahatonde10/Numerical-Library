#ifndef _BOARD_H

#define _BOARD_H


#include "Board.h"

Board::Board() : board(SIZE, std::vector<char>(SIZE, '-')) {}

void Board::printBoard() {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

bool Board::isSafe(int row, int col) {
    // Check this row on the left
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < SIZE; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool Board::solveNQueens(int col) {
    if (col >= SIZE) {
        return true;
    }

    for (int i = 0; i < SIZE; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 'Q';
            if (solveNQueens(col + 1)) {
                return true;
            }
            board[i][col] = '-';  // Backtrack
        }
    }

    return false;
}

#endif