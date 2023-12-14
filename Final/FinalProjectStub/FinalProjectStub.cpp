#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define the Room class, which will represent each room in the game.
class Room {
public:
    // Define the Room constructor.
    Room(string name, string description) {
        name_ = name;
        description_ = description;
    }

    // Define a method to add an item to the room.
    void AddItem(string item) {
        items_.push_back(item);
    }

    // Define a method to remove an item from the room.
    void RemoveItem(string item) {
        for (int i = 0; i < items_.size(); i++) {
            if (items_[i] == item) {
                items_.erase(items_.begin() + i);
                return;
            }
        }
    }

    // Define a method to get the room's name.
    string GetName() {
        return name_;
    }

    // Define a method to get the room's description.
    string GetDescription() {
        return description_;
    }

private:
    string name_;
    string description_;
    vector<string> items_;
};

// Define the Player class, which will represent the player in the game.
class Player {
public:
    // Define the Player constructor.
    Player(string name) {
        name_ = name;
        health_ = 100;
    }

    // Define a method to add an item to the player's inventory.
    void AddToInventory(string item) {
        inventory_.push_back(item);
    }

    // Define a method to remove an item from the player's inventory.
    void RemoveFromInventory(string item) {
        for (int i = 0; i < inventory_.size(); i++) {
            if (inventory_[i] == item) {
                inventory_.erase(inventory_.begin() + i);
                return;
            }
        }
    }
    // Define a method to get the player's name.
    string GetName() {
        return name_;
    }

    // Define a method to get the player's health.
    int GetHealth() {
        return health_;
    }
private:
        string name_;
        int health_;
        vector<string> inventory_;
};

// Define the Game class, which will manage the game flow.
class Game {
public:
    // Define the Game constructor.
    Game() {
        // TODO: Initialize the game's rooms, items, and monsters.
    }
    // Define a method to start the game.
    void Start() {
        // TODO: Implement the game's main loop.
    }
    private:
// TODO: Define the game's rooms, items, and monsters.
};

int main() {
// TODO: Prompt the user for their name and create a Player object.

// TODO: Create a Game object and start the game.

return 0;
}
// Define a method to start the game.
void Start() {
    // TODO: Implement the game's main loop.
}
private:
    // TODO: Define the game's rooms, items, and monsters.
};

int main() {
    // TODO: Prompt the user for their name and create a Player object.

    // TODO: Create a Game object and start the game.

    return 0;
}