/* Assignment 5 - Maze
 * Created by: Andrew Edwin Parisee
 * The purpose of this application is to read in the given maze text document and allow for the program to calculate
 * a solution to the maze and display it on the console.
 * Structure code modified from stack.c file.
 * Due Date: Tuesday December 11, 2018 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define MAZE_SIZE 53
typedef struct Node {
    int row;
    int col;
    struct Node *next;
} Node;
Node *top;

void stack_init(){
    top = NULL;
}

void stack_push( int col, int row ){
    Node *node = (Node *)malloc( sizeof(Node) );
    node->row = row;
    node->col = col;
    node->next = top;

    top = node;
}

int stack_pop(){
    Node *node = top;

    if( node != NULL )
    {
        int row = node-> row;
        int col = node-> col;

        top = node->next;

        free( node );

        return row, col;
    }
    return -1;
}

void stack_print() {
    Node *node = top;

    if( node == NULL ) {
        printf("** stack empty **\n");
    }
    else {
        while( node != NULL ) {
            printf("Row: %i, Column: %i", node->row, node->col);
            node = node->next;
        }
        printf("\n");
    }
}

void stack_cleanup() {
    while( top != NULL ) {
        stack_pop();
    }
}

void solve_maze( char maze[MAZE_SIZE][MAZE_SIZE]) {
    int col = 0;
    int row = 1;
    int rowEnd = 49;
    int colEnd = 50;

    // Print the start symbol at the entrance coordinates
    stack_push(col, row);
    maze[top->row][top->col] = '#';

    while(top->row != rowEnd || top->col != colEnd) {

        row = top->row;
        col = top->col;
            // Check to the South
        if(maze[row+1][col] == ' ') {
            maze[row+1][col] = '#';
            stack_push(col, row + 1);
            // Check to the West
        } else if(maze[row][col-1] == ' ') {
            maze[row][col-1] = '#';
            stack_push(col - 1, row);
            // Check to the North
        } else if(maze[row-1][col] == ' ') {
            maze[row-1][col] = '#';
            stack_push(col, row - 1);
            // Check to the East
        } else if(maze[row][col+1] == ' ') {
            maze[row][col+1] = '#';
            stack_push(col + 1, row);
            // Print @ symbol to signify dead end
        } else {
            maze[row][col] = '@';
            stack_pop();
        }
    }
}

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];
    FILE *filePointer;
    char *filename = "maze.txt";

    printf("---------------------------------------------------\n");
    printf("----------------Assignment 5 - Maze----------------\n");
    printf("---------------------------------------------------\n\n");

    filePointer = fopen(filename, "r");
    // Read file until while loop hits end of file
    int currentLineCount = 0;

    while(!feof(filePointer)) {
        fgets(maze[currentLineCount], MAZE_SIZE, filePointer);
        if(!feof(filePointer)) {
            //printf("%s", maze[currentLineCount]);
        }
        currentLineCount++;
    }
    // Length of first line
    long column = strlen(maze[0]);
    // Set position of the filePointer
    fseek(filePointer, 0, SEEK_END);
    // fileTell used to show the character count at current position
    long row = ftell(filePointer);
    fclose(filePointer);

    row = row / column;
    // Print the calculated file size
    //printf("File Size: (%ld, %ld)\n", row, column);

    solve_maze(maze);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            // Overwrite the @ symbol to blank spaces
            if(maze[r][c] == '@') {
                printf(" ");
            } else{
                printf("%c", maze[r][c]);
            }
        }
    }
    return 0;
}