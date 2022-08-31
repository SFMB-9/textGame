#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "json.hpp"
#include "player.hpp"

using json = nlohmann::json;

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void color(int color) {
    std::cout << "\033[0;" << color << "m";
}

/*New Game*/
void newGame(){
    color(32);
    std::cout << "New Game" << std::endl;
    std::cout << "Select a save slot:" << std::endl;
    std::cout << "1. Save 1" << std::endl;
    std::cout << "2. Save 2" << std::endl;
    std::cout << "3. Save 3" << std::endl;
    std::cout << "> ";
    int choice;
    std::cin >> choice;
    std::cout << "Welcome" << std::endl;
}

void loadGame(){

}

void saveGame(){

}
auto newSavefile() {
    json savefile;
    savefile["player"] = {
        {"name", "Player"},
        {"hp", 100},
        {"max_hp", 100},
        {"inv", {
            {"item", {
                {"name", "Item"},
                {"description", "Description"},
                {"weight", 1}
            }}
        }},
        {"flags", {
            {"flag", {
                {"name", "Flag"},
                {"description", "Description"},
                {"complete", false}
            }}
        }}
    };
    return savefile;
}
auto readJson(std::string path){
    std::ifstream i(path);
    json j;
    i >> j;
    std::cout << j << std::endl;
}

void printJson(nlohmann::json json){
    std::cout << json.dump(4) << std::endl;
}

void menu() {
    std::cout << "STORIX" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "> ";
    int choice;
    std::cin >> choice;
    if(choice == 1){
        newGame();

    } else if(choice == 2){
        std::cout << "Load Game" << std::endl;
        std::cout << "Select a save slot:" << std::endl;
        std::cout << "1. Save 1" << std::endl;
        std::cout << "2. Save 2" << std::endl;
        std::cout << "3. Save 3" << std::endl;
        std::cout << "> ";
        int choice;
        std::cin >> choice;

    } else if(choice == 3){
        std::cout << "Quit" << std::endl;
    } else {
        std::cout << "Invalid Choice" << std::endl;
    }
}

int main() {
    clearScreen();
    menu();
    return 0;
}