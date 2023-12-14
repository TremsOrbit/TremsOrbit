#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Forward declarations
class Room;
class Item;
class Monster;

// Player class
class Player {
public:
    Player(string name) {
        this->name = name;
        this->health = 100;
    }

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int health) {
        this->health = health;
    }

    void addToInventory(Item* item) {
        inventory.push_back(item);
    }

    vector<Item*> getInventory() {
        return inventory;
    }

private:
    string name;
    int health;
    vector<Item*> inventory;
};

// Room class
class Room {
public:
    Room(string name, string description) {
        this->name = name;
        this->description = description;
    }

    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }

    void addItem(Item* item) {
        items.push_back(item);
    }

    vector<Item*> getItems() {
        return items;
    }

    void setNorth(Room* room) {
        exits["north"] = room;
    }

    void setSouth(Room* room) {
        exits["south"] = room;
    }

    void setEast(Room* room) {
        exits["east"] = room;
    }

    void setWest(Room* room) {
        exits["west"] = room;
    }

    Room* getExit(string direction) {
        if (exits.find(direction) != exits.end()) {
            return exits[direction];
        }
        else {
            return NULL;
        }
    }

private:
    string name;
    string description;
    vector<Item*> items;
    map<string, Room*> exits;
};

// Item class
class Item {
public:
    Item(string name, string description) {
        this->name = name;
        this->description = description;
    }

    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }

private:
    string name;
    string description;
};

// Monster class
class Monster {
public:
    Monster(string name, int health, int damage) {
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int health) {
        this->health = health;
    }

    int getDamage() {
        return damage;
    }

private:
    string name;
    int health;
    int damage;
};

// Function prototypes
void printHelp();
void printInventory(Player* player);
void printRoom(Room* room);
void printItems(vector<Item*> items);
void printMonsters(vector<Monster*> monsters);
void printHealth(Player* player);
void movePlayer(Player* player, Room* room, string direction);
void takeItem(Player* player, Room* room, string itemName);
void dropItem(Player* player, Room* room, string itemName);
void fightMonster(Player* player, Room* room, Monster* monster);
Room* startRoom = new Room("Starting Room", "You are in a dimly lit room. There is a door to the north.");
Room* northRoom = new Room("North Room", "You are in a cold room. There is a door to the south and a key on the table.");
Room* southRoom = new Room("South Room", "You are in a warm room. There is a door to the north and a locked chest in the corner.");
Room* eastRoom = new Room("East Room", "You are in a bright room. There is a door to the west and a puzzle on the wall.");
Room* westRoom = new Room("West Room", "You are in a dark room. There is a door to the east and a monster blocking your way.");
Room* puzzleRoom = new Room("Puzzle Room", "You are in a room with a puzzle. Solve the puzzle to continue.");
Room* monsterRoom = new Room("Monster Room", "You are in a room with a scary monster!");

// Create items
Item* keyItem = new Item("Key", "A small key that unlocks a door.");
Item* chestItem = new Item("Treasure Chest", "A treasure chest full of gold.");
Item* puzzleItem = new Item("Puzzle Box", "A box with a puzzle on it.");

// Add items to rooms
northRoom->addItem(keyItem);
southRoom->addItem(chestItem);
eastRoom->addItem(puzzleItem);

// Add connections between rooms
startRoom->setExit("north", northRoom);
northRoom->setExit("south", startRoom);
northRoom->setExit("east", eastRoom);
southRoom->setExit("north", startRoom);
eastRoom->setExit("west", northRoom);
eastRoom->setExit("east", monsterRoom);
westRoom->setExit("east", startRoom);
monsterRoom->setExit("west", eastRoom);
puzzleRoom->setExit("west", southRoom);

// Add puzzles to rooms
eastRoom->setPuzzle(new Puzzle("Puzzle 1", "Solve the puzzle to continue.", "Answer"));

// Add monsters to rooms
westRoom->setMonster(new Monster("Scary Monster", 10));

// Set starting room
currentRoom = startRoom;