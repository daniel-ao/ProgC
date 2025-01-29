#include <stdio.h>

// Define the size of the game map (grid)
#define MAP_SIZE_X 11
#define MAP_SIZE_Y 11

// Define a 2D array to represent the game map
char gameMap[MAP_SIZE_Y][MAP_SIZE_X];

// Function to initialize the game map
void initializeGameMap() {
    // Initialize the entire grid with spaces
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            gameMap[y][x] = ' ';
        }
    }

    // Place specific symbols and characters on the map as needed
    gameMap[1][2] = '@';
    gameMap[1][8] = '*';
    gameMap[2][1] = '*';
    gameMap[3][8] = '@';
    gameMap[4][1] = '!';
    gameMap[5][5] = 'Y';
    gameMap[5][7] = '#';
    gameMap[5][8] = '#';
    gameMap[6][1] = 'R';
    gameMap[6][7] = '#';
    gameMap[6][8] = '#';
    gameMap[7][1] = '!';
    gameMap[7][3] = '*';
    gameMap[7][8] = '@';
    gameMap[8][1] = '!';
    gameMap[8][2] = '*';
    gameMap[8][7] = '@';
    gameMap[9][1] = '!';
    gameMap[9][8] = '!';
    
}

// Function to print the game map
void printGameMap() {
    // Print the top border
    printf("  ");
    for (int x = 0; x < MAP_SIZE_X; x++) {
        printf("%X ", x);
    }
    printf("\n");

    // Print the map grid with borders
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        printf("%X|", y); // Print the leftmost coordinate for each row
        for (int x = 0; x < MAP_SIZE_X; x++) {
            // Print each cell of the game map
            printf("%c ", gameMap[y][x]);
        }
        printf("|\n"); // Right border and move to the next row
    }
}

int main() {
    // Initialize the game map
    initializeGameMap();

    // Print the game map
    printGameMap();

    return 0;
}

