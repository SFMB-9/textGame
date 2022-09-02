#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "json.hpp"
#include "player.hpp"
#include "slot.hpp"
#include "style.hpp"
#include "inventory.hpp"

using Json = nlohmann::json;

/*New Game*/
void newGame(){
    //Build slots
    Slot slot1 = Slot("savefiles/save1.json");
    std::cout << "\nslot1 built";
    Slot slot2 = Slot("savefiles/save2.json");
    std::cout << "\nslot2 built";
    Slot slot3 = Slot("savefiles/save3.json");
    std::cout << "\nslot3 built";
    
    std::cout << CLEAR;
    std::cout << "\nSelect a save slot:";
    std::cout << "\n" << slot1;
    std::cout << "\n" << slot2;
    std::cout << "\n" << slot3;
    std::cout << "\n> ";
    int choice;
    std::cin >> choice;
    std::cout << "Welcome";
}


void loadGame(){

}

void saveGame(){

}

auto readJson(std::string path){
    std::ifstream i(path);
    Json j;
    i >> j;
    std::cout << j << "\n";
}

void printJson(Json json){
    std::cout << json.dump(4) << "\n";
}

void menu() {
    std::cout << BOLD_CYAN << "STORIX" << RESET;
    std::cout << "\nNew Game";
    std::cout << "\n2. Load Game";
    std::cout << "\n3. Quit";
    std::cout << "\n> ";
    int choice;
    std::cin >> choice;
    if(choice == 1){
        newGame();

    } else if(choice == 2){

    } else if(choice == 3){
        std::cout << "\nQuit";
    } else {
        std::cout << "\nInvalid Choice";
    }
}

int main() {
    std::cout << CLEAR;
    menu();
    return 0;
}