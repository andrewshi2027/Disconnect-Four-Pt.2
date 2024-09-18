#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "hw1.h"

char board[MAX_ROWS][MAX_COLS] = {0};
/*
Hint: Consider adding a global variable to store a string large enough to store a board.
*/

void initialize_board(const char *initial_state, int num_rows, int num_cols) {
    //Convert String to Array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; i < num_cols; j++) {
            board[i][j] = initial_state[num_cols * i + j];
        }
    }
}

//Helper method for checkFour()
int helper (char a, char b, char c, char d) {
    return (a == b && b == c && c ==d && a != '-');
}

//Checks if there are any 4-in-a-rows in the board
int checkFour(const char *initial_state, int num_rows, int num_cols) {
    //Initialize Board
    initialize_board(initial_state, num_rows, num_cols);

    //Check horizontal 4 in a row
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; i < num_cols - 4; j++) {
            if (helper(board[i][j], board[i][j+1], board[i][j+2], board[i][j+3])) {
                return 1; 
            }
        }
    }

    //Check vertical 4 in a row
    for (int i = 0; i < num_rows - 4; i++) {
        for (int j = 0; i < num_cols; j++) {
            if (helper(board[i][j], board[i+1][j], board[i+2][j], board[i+3][j])) {
                return 1;
            }
        }
    }

    //Check diagonal 4 in a row (top-left to bottom-right)
    for (int i = 0; i < num_rows - 4; i++) {
        for (int j = 0; i < num_cols - 4; j++) {
            if (helper(board[i][j], board[i+1][j+1], board[i+2][j+2], board[i+3][j+3])) {
                return 1;
            }
        }
    }
    //Check diagonal 4 in a row (bottom-left to top-right)
    for (int i = 3; i < num_rows; i++) { //Start at row 3 to avoid out of bounds
        for (int j = 0; i < num_cols - 4; j++) {
            if (helper(board[i][j], board[i-1][j+1], board[i-2][j+2], board[i-3][j+3])) {
                return 1;
            }
        }
    }

    //If no 4-in-a-row
    return 0; 
}

int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   
    //Variables
    int count_x = 0; //# of x's
    int count_o = 0; //# of o's
    int isEmpty = 0; //Track if there are any empty spots
    int invalid_char = 0; //Track if there are any invalid chars

    //Initialize Board
    initialize_board(initial_state, num_rows, num_cols);

    //Traverse through board to count # of x's and o's and check for invalid characters
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            char current = board[i][j];
            if (current == 'x') {
                count_x++;
            }
            else if (current == 'o') {
                count_o++;
            }
            else if (current == '-') {
                isEmpty = 1; //has empty cells
            }
            else {
                invalid_char = 1; //has invalid chars
            }
        }
    }

    //INITIAL_BOARD_INVALID_CHARACTERS
    if (invalid_char == 1) {
        return INITIAL_BOARD_INVALID_CHARACTERS;
    }

    //FOUND_SOLUTION
    if (checkFour(initial_state, num_rows, num_cols) == 0) {
        return INITIAL_BOARD_FOUR_IN_A_ROW;
    }

    //Heuristics: For each empty cell, check if placing an 'x' or 'o' creates a forced move
    int made_progress = 1; //Tracks if any forced moves are made
    int forced_move = 0; //Tracks if a forced move is made during the heuristic

    while (made_progress == 0) {
        made_progress = 0;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (board[i][j] == '-') {
                    //x is placed
                    board[i][j] = 'x';
                    //If the x creates a 4-in-a-row
                    if (checkFour(initial_state, num_rows, num_cols) == 1) {
                        board[i][j] == 'o';
                        made_progress = 1;
                        forced_move = 1;
                    }
                    else {
                        //o is placed
                        board[i][j] = 'o';
                        //if the o creates a 4-in-a-row
                        if (checkFour(initial_state, num_rows, num_cols) == 1) {
                            board[i][j] = 'x';
                            made_progress = 1;
                            forced_move = 1;
                        }
                        else {
                            //Reset the cell if no forced move
                            board[i][j] = '-';
                        }
                    }
                }
            }
        }
    }

    //After heuristic, check if there are empty cells
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; i < num_cols; j++) {
            if (board[i][j] == 0) {
                //If there are still empty cells but no forced moves are possible
                if (forced_move == 0) {
                    return INITIAL_BOARD_NO_SOLUTION;
                }
                return HEURISTICS_FAILED; //Some empty cells remain but heuristic failed
            }
        }
    }
    
    //If no invalid characters, no four-in-a-row, and no empty spots
    *num_x = count_x;
    *num_o = count_o;

    return FOUND_SOLUTION;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 

    return 0;
}
