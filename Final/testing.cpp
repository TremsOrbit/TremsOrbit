

#include "game.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing game initialization") {
    Game game;
    CHECK(game.getCurrentRoom() == "start");
    CHECK(game.isGameOver() == false);
}

TEST_CASE("testing movement between rooms") {
    Game game;
    game.movePlayer("east");
    CHECK(game.getCurrentRoom() == "hallway");
    game.movePlayer("south");
    CHECK(game.getCurrentRoom() == "dungeon");
    game.movePlayer("west");
    CHECK(game.getCurrentRoom() == "start");
    game.movePlayer("north");
    CHECK(game.getCurrentRoom() == "library");
}

TEST_CASE("testing player actions") {
    Game game;
    game.performAction("look");
    CHECK(game.getCurrentRoomDescription() == "You are standing in the starting room.");
    game.performAction("examine key");
    CHECK(game.getPlayerInventory() == "You don't have that item.");
    game.performAction("take key");
    CHECK(game.getPlayerInventory() == "key");
    game.performAction("use key");
    CHECK(game.getCurrentRoomDescription() == "You unlocked the door and entered the hallway.");
}

TEST_CASE("testing game over condition") {
    Game game;
    game.movePlayer("south");
    CHECK(game.isGameOver() == true);
    CHECK(game.getGameOverMessage() == "You were captured by the guards and thrown in the dungeon. Game over.");
}

