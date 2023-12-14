#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Room class
class Room {
public:
    std::string name;
    std::string description;
    bool locked;
    std::string lockDescription;
    int requiredItemIndex;

    Room(std::string roomName, std::string roomDescription, bool isLocked, std::string lockDesc, int reqItemIndex)
        : name(roomName), description(roomDescription), locked(isLocked), lockDescription(lockDesc), requiredItemIndex(reqItemIndex) {}
};

// Player class
class Player {
public:
    std::string name;
    int health;
    std::vector<std::string> inventory;
    int currentRoomIndex;

    Player(std::string playerName, int playerHealth, int startRoomIndex) 
        : name(playerName), health(playerHealth), currentRoomIndex(startRoomIndex) {}

    bool hasItem(std::string itemName) {
        auto it = std::find(inventory.begin(), inventory.end(), itemName);
        return it != inventory.end();
    }

    void addItem(std::string itemName) {
        inventory.push_back(itemName);
    }

    void removeItem(int itemIndex) {
        inventory.erase(inventory.begin() + itemIndex);
    }

    void printInventory() {
        std::cout << "Inventory: ";
        if (inventory.size() == 0) {
            std::cout << "empty";
        } else {
            for (int i = 0; i < inventory.size(); i++) {
                std::cout << inventory[i];
                if (i != inventory.size() - 1) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << std::endl;
    }

    bool isAlive() {
        return health > 0;
    }
};

// Monster class
class Monster {
public:
    std::string name;
    int health;
    int damage;

    Monster(std::string monsterName, int monsterHealth, int monsterDamage) 
        : name(monsterName), health(monsterHealth), damage(monsterDamage) {}

    bool isAlive() {
        return health > 0;
    }
};

// Puzzle class
class Puzzle {
public:
    std::string question;
    std::string answer;

    Puzzle(std::string puzzleQuestion, std::string puzzleAnswer) 
        : question(puzzleQuestion), answer(puzzleAnswer) {}
};

// Game class
class Game {
public:
    std::vector<Room> rooms;
    std::vector<Monster> monsters;
    std::vector<Puzzle> puzzles;
    std::vector<std::string> items;
    Player player;

    Game() {}

    // Helper function to check if player has required item for room
    bool playerHasRequiredItem(int roomIndex) {
        int requiredItemIndex = rooms[roomIndex].requiredItemIndex;
        if (requiredItemIndex == -1) {
            return true;
        } else {
            std::string requiredItem = items[requiredItemIndex];
            return player.hasItem(requiredItem);
        }
    }

    // Helper function to check if player can unlock locked room
    bool canUnlockRoom(int roomIndex) {
        if (!rooms[roomIndex].locked) {
            return true;
        } else {
            int requiredItemIndex = rooms[roomIndex].requiredItemIndex;
            if (requiredItemIndex == -1) {
                std::cout << "The room is locked." << std::endl;
                std::cout << rooms[roomIndex].lockDescription << std::endl;
                return false;
            } else {
                std::string requiredItem = items[