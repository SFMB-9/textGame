#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "json.hpp"
#include "player.hpp"
#include "slot.hpp"

using Json = nlohmann::json;

#define CLEAR "\033[2J\033[1;1H"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"
#define BOLD "\033[1m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"
#define BOLD_BLACK "\033[1;30m"
#define UNDERLINE "\033[4m"
#define REVERSE "\033[7m"
#define HIDE "\033[8m"

/*New Game*/
void newGame(){
    std::cout << "Welcome to the text game!";
    //Build slots
    Slot slot1 = Slot("savefiles/save1.json");
    std::cout << "\nslot1 built";
    Slot slot2 = Slot("savefiles/save2.json");
    std::cout << "\nslot2 built";
    Slot slot3 = Slot("savefiles/save3.json");
    std::cout << "\nslot3 built";
    
    std::cout << "\nNew Game";
    std::cout << "\nSelect a save slot:";
    std::cout << slot1 << std::endl;
    std::cout << "\n1. Save 1";
    std::cout << "\n2. Save 2";
    std::cout << "\n3. Save 3";
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
        std::cout << "Load Game";
        std::cout << "\nSelect a save slot:";
        std::cout << u8"\n\u2554 \u2557\n 1. Save 1";
        std::cout << "\n╔═══════╗\n║2. Save 2║\n╚════════╝";
        std::cout << "\n╔═══════╗\n║3. Save 3║\n╚════════╝";
        std::cout << "\n> ";
        int choice;
        std::cin >> choice;

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