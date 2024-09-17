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

int checkFour(const char *initial_state, int num_rows, int num_cols) {
    board[i][j]
    //Check vertical 4 in a row
    //Check horizontal 4 in a row
    //Check diagonal 4 in a row
}

int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   

    return 0;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 

    return 0;
}
