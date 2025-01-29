#include <stdio.h>
#include <string.h>

// Define a structure for Rahan's stats
typedef struct {
    int healthPoints; // Points de vie
    int health;       // Santé
    int strength;     // Force
    int speed;        // Vitesse
} Stats;

// Define a structure for equipment items
typedef struct {
    char description[50];
    int statBonus;
    char class[50];
} Equipment;

// Initialize Rahan's stats
Stats rahan = {50, 50, 10, 1};

// Initialize an empty inventory for Rahan
Equipment inventory[10]; // Assuming Rahan can carry a maximum of 10 items
int itemCount = 0; // Current number of items in the inventory

// Function to add an item to Rahan's inventory
void addItemToInventory(Equipment item) {
    if (itemCount < 10) {
        inventory[itemCount++] = item;
        printf("Rahan picked up: %s\n", item.description);
        
        // Update Rahan's stats based on the item class
        if (strcmp(item.class, "chaussures") == 0) {
            rahan.speed += item.statBonus;
        } else if (strcmp(item.class, "protections") == 0) {
            rahan.healthPoints += item.statBonus;
        } else if (strcmp(item.class, "armes") == 0) {
            rahan.strength += item.statBonus;
        }
    } else {
        printf("Rahan's inventory is full!\n");
    }
}

// Function to print Rahan's stats
void printStats() {
    printf("Rahan's stats:\n");
    printf("Health Points: %d\n", rahan.healthPoints);
    printf("Health: %d\n", rahan.health);
    printf("Strength: %d\n", rahan.strength);
    printf("Speed: %d\n", rahan.speed);
}

// Main game loop
int main() {
    char command[50];

    // Game continues until Rahan's health is above 0
    while (rahan.health > 0) {
        printf("\nEnter command: ");
        scanf("%49s", command); // Read a command from the user

        if (strcmp(command, "INVOCATION") == 0) {
            printStats(); // If the command is "INVOCATION", print Rahan's stats
        } else {
            printf("Unknown command.\n");
        }
        
        // Here would be the game logic to move Rahan and check for items
        
        // For demonstration, let's say Rahan stepped on an item:
        // (This should normally be part of the game logic where Rahan moves)
        Equipment foundItem = {"bottes en peau de crocro", 10, "chaussures"}; // For example
        addItemToInventory(foundItem);
        
        // Check if Rahan's health has dropped to 0
        if (rahan.health <= 0) {
            printf("Rahan est mort!\n");
            break; // Exit the game loop if Rahan's health is 0
        }
    }

    return 0;
}


