//
// Created by Kristen Wright
//

#include "Queens.h"
#include <iostream>

/**
 * Default constructor that creates an empty board.
 */
NQueens::NQueens() {
    clearBoard();
}

void NQueens::solve()
{
    if (placeQueens(0)) {
        std::cout << "\nSolution found:" << std::endl;
        displayBoard();
    } else {
        std::cout << "\nNo solution found." << std::endl;
    }
    clearBoard();
}

void NQueens::clearBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY; // Sets all squares to empty
        }
    }
}

void NQueens::displayBoard() {
    std::cout << std::endl;
    for (auto & row : board) {
        for (auto & col : row) {
            if (col == QUEEN) {
                std::cout << "Q ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool NQueens::placeQueens(int col) {

    if (col == BOARD_SIZE){
        return true;
    }
    else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (!isUnderAttack(i, col)) {
                setQueen(i, col);

                if (placeQueens(col + 1)) {
                    return true;
                } else{
                    removeQueen(i, col);
                }
            }
        }
    }
    return false;
}

void NQueens::setQueen(int row, int col) {
    board[row][col] = QUEEN;
}

void NQueens::removeQueen(int row, int col) {
    board[row][col] = EMPTY;
}

bool NQueens::isUnderAttack(int row, int col) {

    int row1 = row;
    int col1 = col;

    // check each row
    for(auto & i : board){
        if(i[col] == QUEEN)
            return true;
    }

    // check each col
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[row][i] == QUEEN)
            return true;
    }

    // check diagonal going down to the left
    while(row1 < BOARD_SIZE && col1 >= 0){
        if(board[row1][col1] == QUEEN){
            return true;
        }
        row1++;
        col1--;
    }

    row1 = row;
    col1 = col;
    // check diagonal going up to the left
    while(row1 >= 0 && col1 >= 0){
        if(board[row1][col1] == QUEEN){
            return true;
        }
        row1--;
        col1--;
    }
    return false;
}


