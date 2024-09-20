#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hw1.h"

//Checks if the board is full
int isBoardFull(int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (board[i][j] == '-') {
                return 0; //Board is not full
            }
        }
    }
    return 1; //Board is full
}

//Print Board
void printBoard(int num_rows, int num_columns) {
    //Print Board
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    assert(argc == 4); //verify that the number of command-line arguments is exactly what we are expecting
    initialize_board(argv[3], (int)strtoul(argv[1], NULL, 10), (int)strtoul(argv[2], NULL, 10));
	//WRITE YOUR CODE HERE

    //Variables
    char piece;
    int row, column; //user input
    int num_rows = (int)strtoul(argv[1], NULL, 10); //number of rows
    int num_columns = (int)strtoul(argv[2], NULL, 10); //number of columns

    while (1) 
    {
        printBoard(num_rows, num_columns);
        
        //User Input for Piece
        while (1) {
            printf("Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &piece); //need space before %c
            if (piece == 'x' || piece == 'o' || piece == 'q') {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }

        //If user chose "q" (quit)
        if (piece == 'q') {
            return 0;
        }

        //User Input for Row
        while (1) {
            printf("Choose a row (0-%d): ", num_rows - 1);
            scanf("%d", &row);
            if (row >= 0 && row < num_rows) {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }

        //User Input for Column
        while (1) {
            printf("Choose a column (0-%d): ", num_columns - 1);
            scanf("%d", &column);

            if (column >= 0 && column < num_columns) {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }

        //Checks if invalid piece choice
        if (board[row][column] != '-') {
            printf("Invalid choice. That space is already occupied.\n");
            continue;
        }
        else {
            //Place piece in array
            board[row][column] = piece;  
        }
        
        
        //Checks if there is a 4-in-a-row
        if (checkFour(argv[3], num_rows, num_columns) == 1) 
        {
            printf("Invalid choice. You have created 4-in-a-row.\n");
            //board[row][column] = '-';
            continue;
        }  
        
        //Checks if winning board
        if (isBoardFull(num_rows, num_columns) == 1) {
            if (checkFour(argv[3], num_rows, num_columns) == 0) 
            {
                printf("Congratulations, you have filled the board with no 4-in-a-rows!\n");
                printBoard(num_rows, num_columns);
                break;
            }
        }
    }
    return 0;
}
