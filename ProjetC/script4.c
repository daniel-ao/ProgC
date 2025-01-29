#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAP_SIZE_X 11
#define MAP_SIZE_Y 11
#define RAHAN_SYMBOL 'R'
#define OBSTACLE_ROCK '#'
#define FOOD_SYMBOL '*'
#define MONSTER_SYMBOL '@'
#define OBJECT_SYMBOL '!'
#define MAX_INVENTORY 10

typedef struct {
    int healthPoints; 
    int health;       
    int strength;     
    int speed;        
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

/*Initialize Rahan's stats*/
Stats rahan = {50, 50, 10, 1};
Equipment inventory[MAX_INVENTORY];
int itemCount = 0;
char map[MAP_SIZE_X][MAP_SIZE_Y]; 
int rahanX = 5; 
int rahanY = 6; 


char gameMap[MAP_SIZE_Y][MAP_SIZE_X];


void initializeGameMap() {
    /* Initialize the entire grid with spaces*/
    int y;
    int x;
    int i;
    int maxFood = 5;
    int maxObjects = 3;
    int maxMonsters = 2;
    int maxRocks = 3;
    char items[] = {'*', '!', '@', '#'};
    for (y = 0; y < MAP_SIZE_Y; y++) {
        for (x = 0; x < MAP_SIZE_X; x++) {
            gameMap[y][x] = ' ';
        }
    }

    gameMap[5][5] = 'Y';
    gameMap[rahanY][rahanX] = 'R';
    /* Randomly place items on the map*/
    


    for (i = 0; i < maxFood + maxObjects + maxMonsters + maxRocks; i++) {
        char item;

        if (i < maxFood) {
            item = items[0]; 
        } else if (i < maxFood + maxObjects) {
            item = items[1]; 
        } else if (i < maxFood + maxObjects + maxMonsters) {
            item = items[2]; 
        } else {
            item = items[3]; 
        }

        do {
            x = rand() % MAP_SIZE_X;
            y = rand() % MAP_SIZE_Y;
        } while (gameMap[y][x] != ' ' || (x == 5 && y == 5)); 

        gameMap[y][x] = item;
    }
}


void printMap() {
/* Print the top border*/
    int x,y;    
    printf("  ");
    for ( x = 0; x < MAP_SIZE_X; x++) {
        printf("%X ", x);
    }
    printf("\n");
    for ( y = 0; y < MAP_SIZE_Y; y++) {
        printf("%X|", y); 
        for ( x = 0; x < MAP_SIZE_X; x++) {
            printf("%c ", gameMap[y][x]);
        }
        printf("|\n"); 
    }
}



void printInventory() {
    int i;
    printf("Rahan's Inventory:\n");
    for (i = 0; i < itemCount; i++) {
        printf("%d: %s\n", i + 1, inventory[i].description);
    }
    if (itemCount == 0) {
        printf("The inventory is empty.\n");
    }
}


void addItemToInventory(Equipment item) {
    if (itemCount < MAX_INVENTORY) {
        inventory[itemCount++] = item;
        printf("Rahan picked up: %s\n", item.description);

        /* Update Rahan's stats based on the item class*/
        if (strcmp(item.class, "speed") == 0) { 
            rahan.speed += item.statBonus;
        } else if (strcmp(item.class, "strength") == 0) {
            rahan.strength += item.statBonus;
        }
    } else {
        printf("Rahan's inventory is full!\n");
    }
}

void consumeFood() {
    /* Increase Rahan's health. Adjust the value as per your game's design.*/
    int healthGain = 5; /*Example: food increases health by 5*/
    rahan.health += healthGain;
    if (rahan.health > rahan.healthPoints) {
        rahan.health = rahan.healthPoints; 
    }
}


void fightMonster() {
    /* Example combat logic
     This can be expanded based on how complex you want the combat system to be */
    int monsterStrength = 5; 

    /* Rahan fights and loses some health*/
    rahan.health -= monsterStrength;

    /* Check if Rahan's health falls below 0*/
    if (rahan.health < 0) {
        rahan.health = 0; 
    }

    printf("Rahan fought a monster and his health is now %d.\n", rahan.health);
}


void pickUpObject(Equipment object) {
    /* Placeholder for object pickup logic
     You can add logic to modify Rahan's stats or add the item to his inventory */

    printf("Rahan picked up an object!\n");

    rahan.strength += 2;

    /* If you have different types of objects, you may need to pass more information
     to this function to know which stat to increase or what item to add to the inventory */
}

void printStats()
{
printf("Rahan's stats:\n");
printf("Health Points: %d\n", rahan.healthPoints);
printf("Health: %d\n", rahan.health);
printf("Strength: %d\n", rahan.strength);
printf("Speed: %d\n", rahan.speed);
}






void updateMap(int oldY, int oldX, int newY, int newX) {
 
    gameMap[oldY][oldX] = ' ';

    
    gameMap[newY][newX] = 'R';

    /* If Rahan moved onto a tile with an item (food, object, etc.), clear that item
     Note: This depends on your game design. You might want to leave items on the map
     even after Rahan interacts with them, or you might want to remove them.
     Here we're removing the item from the map for simplicity.
     If food or object is consumed or picked up, remove it from the map*/
    if (gameMap[newY][newX] == '*' || gameMap[newY][newX] == '!') {
        gameMap[newY][newX] = ' ';
    }

  
    if (gameMap[newY][newX] == '@') {
       gameMap[newY][newX] = ' ';
   }
}



void moveRahan(char* direction) {
    int dx = 0, dy = 0;
    int nextX;
    int nextY;
    char tile;
    Equipment foundItem;
    if (strcmp(direction, "HAUT") == 0) dy = -1;
    else if (strcmp(direction, "BAS") == 0) dy = 1;
    else if (strcmp(direction, "GAUCHE") == 0) dx = -1;
    else if (strcmp(direction, "DROITE") == 0) dx = 1;

     nextX = rahanX + dx;
     nextY = rahanY + dy;

    /*Boundary check*/
    if (nextX < 0 || nextX >= MAP_SIZE_X || nextY < 0 || nextY >= MAP_SIZE_Y) {
        return; /* Stop if next move is outside the map*/
    }

     tile = gameMap[nextY][nextX];
    switch (tile) {
        case OBSTACLE_ROCK: 
            return;
        case FOOD_SYMBOL: 
            consumeFood();
            break;
        case MONSTER_SYMBOL: 
            fightMonster();
            break;
        case OBJECT_SYMBOL: 
            pickUpObject(foundItem);
            break;
        
    }

    updateMap(rahanY, rahanX, nextY, nextX);
    rahanX = nextX;
    rahanY = nextY;
}


int main() {
    char command[50];

    /* Initialize the game map and other game state variables*/
    initializeGameMap();

    /* Game continues until Rahan's health is above 0*/
    while (rahan.health > 0) {
        printf("\nEnter command: ");
        scanf("%49s", command); /* Read a command from the user*/

        /* Handle movement commands*/
        if (strcmp(command, "HAUT") == 0 || strcmp(command, "BAS") == 0 ||
            strcmp(command, "GAUCHE") == 0 || strcmp(command, "DROITE") == 0) {
            moveRahan(command);
            printMap(); 
        }
        else if (strcmp(command, "INVOCATION") == 0) {
            printStats(); /*Display Rahan's stats*/
        }
        else if (strcmp(command, "VISION") == 0) {
            printMap(); /*Display the map*/
        }
        /* to display the inventory*/
        else if (strcmp(command, "TRIER") == 0) {
            printInventory();
         }
        else {
            printf("Unknown command.\n");
        }

        /*Check if Rahan's health has dropped to 0*/
        if (rahan.health <= 0) {
            printf("Rahan est mort!\n");
            break; 
        }
    }

    return 0;
}