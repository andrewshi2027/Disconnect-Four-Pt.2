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

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; i < num_cols; j++) {
            board[i][j] = initial_state[num_cols * i + j];
        }
    }
    
    
    //xxx-o--xxo-x---------x-oxoxo-o
    for (int j = 0; j < num_rows; j++); {
        for (int i = 0; i < num_cols; i++) {
            printf("%c ", initial_state[0]);
        }
        printf("\n");
    }

    
}

int checkFour() {

}

int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   

    return 0;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 

    return 0;
}
