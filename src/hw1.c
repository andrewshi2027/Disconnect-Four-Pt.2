#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "hw1.h"
#include <string.h>

char board[MAX_ROWS][MAX_COLS] = {0};
char gen_board[401];
/*
Hint: Consider adding a global variable to store a string large enough to store a board.
*/

 void initialize_board(const char *initial_state, int num_rows, int num_cols) {
    //Convert String to Array
    for (int i=0; i<num_rows; i++)
    {
        for (int j=0; j<num_cols; j++)
        {
            board[i][j] = initial_state[num_cols * i + j];
        }
    }
 }

//Helper method for checkFour()
int helper (char a, char b, char c, char d) {
    return (a == b && b == c && c == d && a != '-'); //4-in-a-row
}

//Checks if there are any 4-in-a-rows in the board
int checkFour(int num_rows, int num_cols) {
    //Initialize Board
    //initialize_board(initial_state, num_rows, num_cols);

    //Check horizontal 4 in a row
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j <= num_cols - 4; j++) {
            if (helper(board[i][j], board[i][j+1], board[i][j+2], board[i][j+3]) == 1) {
                return 1; 
            }
        }
    }

    //Check vertical 4 in a row
    for (int i = 0; i <= num_rows - 4; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (helper(board[i][j], board[i+1][j], board[i+2][j], board[i+3][j]) == 1) {
                return 1;
            }
        }
    }

    //Check diagonal 4 in a row (top-left to bottom-right)
    for (int i = 0; i <= num_rows - 4; i++) {
        for (int j = 0; j <= num_cols - 4; j++) {
            if (helper(board[i][j], board[i+1][j+1], board[i+2][j+2], board[i+3][j+3]) == 1) {
                return 1;
            }
        }
    }
    //Check diagonal 4 in a row (bottom-left to top-right)
    for (int i = 3; i < num_rows; i++) { //Start at row 3 to avoid out of bounds
        for (int j = 0; j <= num_cols - 4; j++) {
            if (helper(board[i][j], board[i-1][j+1], board[i-2][j+2], board[i-3][j+3]) == 1) {
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
            else if (current != 'x' && current != 'o' && current != '-') {
                return INITIAL_BOARD_INVALID_CHARACTERS; //-2
            }
        }
    }

    //INITIAL_BOARD_FOUR_IN_A_ROW
    if (checkFour(num_rows, num_cols) == 1) {
        return INITIAL_BOARD_FOUR_IN_A_ROW; //-1
    }

    //Heuristics: For each empty cell, check if placing an 'x' or 'o' creates a forced move
    while (1) {
        int heuristic_solved = 0;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (board[i][j] == '-') {
                    //Place x
                    board[i][j] = 'x';
                    //If x creates a 4-in-a-row
                    if (checkFour(num_rows, num_cols) == 1) {
                        board[i][j] = 'o';
                        count_o++;
                        heuristic_solved = 1;
                        if (checkFour(num_rows, num_cols) == 1) {
                            return INITIAL_BOARD_NO_SOLUTION; //-3
                        }

                    }
                    else {
                        //Place o
                        board[i][j] = 'o';
                        //If o creates a 4-in-a-row
                        if (checkFour(num_rows, num_cols) == 1) {
                            board[i][j] = 'x';
                            count_x++;
                            heuristic_solved = 1;
                        }
                        else {
                            //Reset the cell if no forced move
                            board[i][j] = '-';
                        }
                    }
                }
            }
        }

        if (heuristic_solved == 0) {
            break;
        }
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if(board[i][j] == '-') {
                return HEURISTICS_FAILED; //0
            }
        }
    }    

    *num_x = count_x;
    *num_o = count_o;
    return FOUND_SOLUTION; //1
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 
    // char *medium_board = (char *)malloc((MAX_ROWS * MAX_COLS + 1) * sizeof(char));
    strcpy(gen_board, final_state);

    int num_x, num_o;

    for (int i = 0; i < num_rows * num_cols; i++) {
        char temp = gen_board[i];
        gen_board[i] = '-';

        if (solve(gen_board, num_rows, num_cols, &num_x, &num_o) == HEURISTICS_FAILED) {
            gen_board[i] = temp;
        }
    }
    gen_board[num_rows * num_cols] = '\0';
    gen_board[400] = '\0';
    
    return gen_board;
}


