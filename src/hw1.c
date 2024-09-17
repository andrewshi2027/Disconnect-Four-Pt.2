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

int checkFour(const char *initial_state, int num_rows, int num_cols) {
    //Check horizontal 4 in a row
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; i < num_cols - 4; j++) {
            if (helper(board[i][j], board[i][j+1], board[i][j + 2], board[i][j + 3])) {
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
            if (helper(board[i][j], board[i+1][j+1], board[i+2][j], board[i+3][j+3])) {
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

    return 0;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 

    return 0;
}
