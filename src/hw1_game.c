#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hw1.h"

int main(int argc, char **argv) {
    assert(argc == 4); //verify that the number of command-line arguments is exactly what we are expecting
    initialize_board(argv[3], (int)strtoul(argv[1], NULL, 10), (int)strtoul(argv[2], NULL, 10));

	//WRITE YOUR CODE HERE
    //Variables
    char piece;
    int row, column; //user input
    int num_rows = (int)strtoul(argv[1], NULL, 10); //number of rows
    int num_columns = (int)strtoul(argv[2], NULL, 10); //number of columns
    char board[] = argv[3]; //string to array
    int length = strlen(board); //length of the array;

    //User Input for Piece
    while (1)
    {
        printf("Choose a piece (x or o) or q to quit: ");
        scanf(" %c", &piece); //need space before %c
        if (piece == 'x' || piece == 'o' || piece == 'q')
        {
            break;
        }
        else
        {
            printf("Invalid choice. ");
        }
    }

    //User Input for Row
    while (1)
    {
        printf("Choose a row (0-%d): ", num_rows - 1);
        scanf("%d", &row);
        if (row >= 0 && row < num_rows)
        {
            break;
        }
        else
        {
            printf("Invalid choice. ");
        }
    }

    //User Input for Column
    while (1)
    {
        printf("Choose a column (0-%d): ", num_columns - 1);
        scanf("%d", &column);

        if (column >= 0 && column < num_columns)
        {
            break;
        }
        else
        {
            printf("Invalid choice. ");
        }
    }

    //Checks if invalid piece choice
    int index = row * num_columns + column; // Calculate the index in the board array
    while (1) {
        if (piece != '-') {
            printf("Invalid choice. That space is already occupied.\n");
        }
        else {
            //Place piece in array
            board[index] = piece;
        }
    }




    return 0;
}
