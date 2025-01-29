#include <stdio.h>

// Define the size of the game map (grid)
#define MAP_SIZE_X 11
#define MAP_SIZE_Y 11

// Define a 2D array to represent the game map
char gameMap[MAP_SIZE_X][MAP_SIZE_Y];

// Function to initialize the game map
void initializeGameMap() {
    // Initialize the top row with numbers 0 to A (hexadecimal format)
    for (int i = 0; i < MAP_SIZE_X; i++) {
        gameMap[0][i] = "0123456789ABCDEF"[i];
    }

    // Initialize the leftmost column with numbers 0 to A (hexadecimal format)
    for (int i = 0; i < MAP_SIZE_Y; i++) {
        gameMap[i][0] = "0123456789ABCDEF"[i];
    }

    // Initialize the rest of the cells with spaces
    for (int i = 1; i < MAP_SIZE_X; i++) {
        for (int j = 1; j < MAP_SIZE_Y; j++) {
            gameMap[i][j] = ' ';
        }
    }

    // Place specific symbols and characters on the map as needed
   	gameMap[2][3] = '@';
	gameMap[2][7] = '*';	
	gameMap[3][3] = '*';
	gameMap[4][10] = '@';
	gameMap[5][1] = '!';
	gameMap[5][2] = 'Y';
	gameMap[5][3] = '#';
	gameMap[5][5] = '#';
	gameMap[6][1] = 'R';
	gameMap[6][3] = '#';
	gameMap[7][3] = '#';
	gameMap[8][1] = '!';
	gameMap[8][3] = '*';
	gameMap[8][5] = '@';
	gameMap[9][3] = '!';
	gameMap[10][3] = '!';


}

// Function to print the game map with coordinates
void printGameMapWithCoordinates() {
    printf(" 0 1 2 3 4 5 6 7 8 9 A\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
    for (int i = 0; i < MAP_SIZE_X; i++) {
        printf("%c|", gameMap[i][0]); // Print the leftmost coordinate for each row
        for (int j = 1; j < MAP_SIZE_Y; j++) {
            // Print each cell of the game map
            printf("%c ", gameMap[i][j]);
        }
        printf("\n"); // Move to the next row
    }
    printf("+-+-+-+-+-+-+-+-+-+-+-+\n");
}

int main() {
    // Initialize the game map
    initializeGameMap();

    // Print the initial game map with coordinates
    printGameMapWithCoordinates();

    return 0;
}

