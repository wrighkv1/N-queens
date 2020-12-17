//
// Created by Kristen Wright
//

#ifndef N_QUEENS_QUEENS_H
#define N_QUEENS_QUEENS_H

//change BOARD_SIZE to get desired board size.
const int BOARD_SIZE = 8; // Squares per row or column.

class NQueens {
public:

    /**
 * Default constructor that creates an empty board.
 */
    NQueens();

    /**
     * Solve the Eight Queens problem by calling recursive solver.
     */
    void solve();

private:

    enum Square {QUEEN, EMPTY }; // States of square.
    Square board[BOARD_SIZE][BOARD_SIZE]; // Chess board.

    /**
    * Sets all squares to empty.
    */
    void clearBoard();

    /**
    * Displays the board.
    */
    void displayBoard();

    /**
    * Places queens in columns of the board beginning at the column numbered by
    * the parameter "column".
    *
    * Precondition: Queens are placed correctly in cols 1 through column - 1.
     *
     * Postcondtion: If a solution is found, each column of the board contains one
     * queen and true is returned. otherwise, false is returned (no solution exists
     * for a queen anywhere in the column). *
     *
     * @param  column The column number to start placing queens.
     * @return Whether or not the Eight Queens problem was solved if a queen was
     *         placed at certain position in the column designated by the input
     *         parameter.
    */
    bool placeQueens(int column);

    /**
     * Sets the square on the board in a given row and column to a queen being present.
     *
     * @param  row    The row index that will contain a queen.
     * @param  column The column index that will contain a queen.
     */
    void setQueen(int row, int col);

    /**
     * Sets the square on the board in a given row and column to be empty.
     *
     * @param  row    The row index that will not contain a queen.
     * @param  column The column index that will not contain a queen.
     */
    void removeQueen(int row, int col);

    /**
     * Determines whether the square on the board at a given row and column
     * is under attack by any queens in cols 1 through column - 1.
     *
     * Precondition: Each col between 1 and column - 1 has a queen placed
     * in a square at a specific row. None of these queens can be attacked
     * by any other queen.
     *
     * Postcondition: If the designated square is under attack, returns true;
     * otherwise, returns false.
     *
     * @param  row  The row index to check if another queen can attack.
     * @param  col The row index to check if another queen can attack.
     * @return
     */
    bool isUnderAttack(int row, int col);
};

#endif //N_QUEENS_QUEENS_H
