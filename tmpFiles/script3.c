#include <stdio.h>
#include <string.h>

#define MAX_INVENTORY 10
#define MAX_MAP_SIZE 11 // Assuming the map is 11x11 as per your image







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

/*Function to print the game map
void printGameMap() {
    
}
*/






typedef struct {
    int healthPoints; // Points de vie
    int health;       // Santé
    int strength;     // Force
    int speed;        // Vitesse
} Stats;

typedef struct {
    char description[50];
    int statBonus;
    char class[50];
} Equipment;

typedef struct {
    char name[50];
    int healthValue;
    char description[100];
} Food;

// Initialize Rahan's stats
Stats rahan = {50, 50, 10, 1};
Equipment inventory[MAX_INVENTORY];
int itemCount = 0;
char map[MAX_MAP_SIZE][MAX_MAP_SIZE]; // This needs to be initialized with your map data
int rahanX = 5; // Set to Rahan's initial X position
int rahanY = 6; // Set to Rahan's initial Y position

void printStats()
{
printf("Rahan's stats:\n");
printf("Health Points: %d\n", rahan.healthPoints);
printf("Health: %d\n", rahan.health);
printf("Strength: %d\n", rahan.strength);
printf("Speed: %d\n", rahan.speed);
}

void addItemToInventory(Equipment item) {
if (itemCount < MAX_INVENTORY) {
inventory[itemCount++] = item;
printf("Rahan picked up: %s\n", item.description);
// Implement the logic to update Rahan's stats based on the item class
} else {
printf("Rahan's inventory is full!\n");
}
}

// Implement consumeFood function based on your game rules
void consumeFood(Food food) {
// Your code here
}

// Implement fightMonster function based on your game rules
void fightMonster() {
// Your code here
}

// Implement updateMap function to reflect changes
void updateMap(int newY, int newX, char symbol) {
// Your code here
}

void moveRahan(char* direction) {
int dx = 0, dy = 0;
if (strcmp(direction, "HAUT") == 0) dy = -1;
else if (strcmp(direction, "BAS") == 0) dy = 1;
else if (strcmp(direction, "GAUCHE") == 0) dx = -1;
else if (strcmp(direction, "DROITE") == 0) dx = 1;
for (int i = 0; i < rahan.speed; ++i) {
    int nextX = rahanX + dx;
    int nextY = rahanY + dy;

    if (nextX < 0 || nextX >= MAX_MAP_SIZE || nextY < 0 || nextY >= MAX_MAP_SIZE) {
        break; // Stop if next move is outside the map
    }
    char tile = map[nextY][nextX];
    switch (tile) {
        case 'R': // Rock
            // Rahan stops before the rock
            if (i > 0) { // Make sure we don't stop Rahan if the rock is on his first move
                i = rahan.speed; // End loop, Rahan stops before the rock
            }
            break;
        case '*': // Food
            // Consume food and increase health
            // Assume we have a function that returns food based on map symbol
            // Food foundFood = getFoodFromSymbol(tile);
            // consumeFood(foundFood);
            break;
        case 'M': // Monster
            fightMonster();
            // Assume fightMonster handles the outcome of the fight
            i = rahan.speed; // End loop, Rahan stops to fight the monster
            break;
        // Add cases for other items that Rahan can interact with
    }

    // If Rahan hasn't stopped, update his position
    if (i < rahan.speed) {
        rahanX = nextX;
        rahanY = nextY;
        updateMap(rahanY, rahanX, 'R'); // 'R' to represent Rahan's new position
    }
}
}
void printMap() {
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
    char command[50];

    // Initialize the game map
    initializeGameMap();
    

    // Game continues until Rahan's health is above 0
    while (rahan.health > 0) {
        printf("\nEnter command: ");
        scanf("%49s", command); // Read a command from the user

        // Handle movement commands
        if (strcmp(command, "HAUT") == 0 || strcmp(command, "BAS") == 0 ||
            strcmp(command, "GAUCHE") == 0 || strcmp(command, "DROITE") == 0) {
            moveRahan(command);
            printMap(); // Optionally print the map after each move
        }
        else if (strcmp(command, "INVOCATION") == 0) {
            printStats();
        }
        else if (strcmp(command, "VISION") == 0) {
            printMap();
        }
       
        else {
            printf("Unknown command.\n");
        }

        // Check if Rahan's health has dropped to 0
        if (rahan.health <= 0) {
            printf("Rahan est mort!\n");
            break; // Exit the game loop if Rahan's health is 0
        }
    }

    return 0;
}
