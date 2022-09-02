#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "inventory.hpp"
#include "json.hpp"
#include "player.hpp"
#include "render.hpp"
#include "slot.hpp"
#include "style.hpp"

using Json = nlohmann::json;

void eraseSlot(int slot) {
    std::string slot_path = "savefiles/save" + std::to_string(slot) + ".json";
    std::ofstream savefile_stream(slot_path);
    Json savefile;
    savefile["savedata"]["data"] = false;
    savefile["savedata"]["player"]["name"] = "New game";
    savefile["savedata"]["player"]["location"] = "none";
    savefile["savedata"]["player"]["inventory"] = {};
    savefile["savedata"]["settings"]["slotColor"] = "white";
    savefile["savedata"]["gameStats"]["playTime"] = 0;
    savefile["savedata"]["gameStats"]["deaths"] = 0;
    savefile["savedata"]["gameStats"]["kills"] = 0;
    savefile["savedata"]["gameStats"]["completeQuests"] = 0;
    savefile["savedata"]["gameStats"]["failedQuests"] = 0;
    savefile["savedata"]["gameStats"]["completionPercentage"] = 0;
    savefile_stream << savefile;
}

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
    int slotChoice;
    std::cin >> slotChoice;
    Slot *selectedSlot;
    if(slotChoice == 1){
        selectedSlot = &slot1;
    } else if(slotChoice == 2){
        selectedSlot = &slot2;
    } else if(slotChoice == 3){
        selectedSlot = &slot3;
    } else {
        std::cout << "\nInvalid choice";
        return;
    }
    std::cout << "\n" << selectedSlot->savefile["savedata"]["data"];
    if (selectedSlot->savefile["savedata"]["data"]){
        std::cout << "\nThis slot is already in use";
            selectedSlot->print();
        std::cout << "\nDo you want to overwrite it? (y/n)";
        std::cout << "\n> ";
        std::string choice;
        std::cin >> choice;
        if(choice == "y"){
            std::cout << "\nOverwriting...";
            eraseSlot(slotChoice);
        } else {
            std::cout << "\nAborting...";
            return;
        }
        return;
    }
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

json newSavefile() {
    json savefile = {
        {"savedata", {
            {"data", false},
            {"player", {
                {"name", "New game"},
                {"location", "none"},
                {"inventory", {}}
            }},
            {"settings", {
                {"slotColor", "white"}
            }},
            {"gameStats", {
                {"playTime", 0},
                {"deaths", 0},
                {"kills", 0},
                {"completeQuests", 0},
                {"failedQuests", 0},
                {"completionPercentage", 0}
            }}
        }}
    };
    return savefile;
}

void draw(){
    bool drawing = true;
    while(drawing){
        std::cout << CLEAR;
        std::cout << "1. Box of n * m";
        std::cout << "\n2. Box of n * m with border";
        std::cout << "\n3. Box factory (Experimental)";
        std::cout << "\n> ";
        int command;
        std::cin >> command;
        if(command == 1){
            std::cout << "\nWidth: ";
            int width;
            std::cin >> width;
            std::cout << "Height: ";
            int height;
            std::cin >> height;
            //std::cout << CLEAR;
            std::cout << box({{"dimensions", json::array({width, height})}});
            std::cout << "Press enter to continue";
            std::cin.ignore();
        } else if(command == 2){
            std::cout << "\nWidth: ";
            int width;
            std::cin >> width;
            std::cout << "Height: ";
            int height;
            std::cin >> height;
            std::cout << CLEAR;
            std::cout << box({{"dimensions", {width, height}}, {"border", true}});
            std::cout << "Press enter to continue";
            std::cin.ignore();
            std::cin.ignore();
        } else if(command == 3){
            std::cout << "\nWidth: ";
            int width;
            std::cin >> width;
            std::cout << "Height: ";
            int height;
            std::cin >> height;
            std::cout << "Border (y/n): ";
            std::string border;
            std::cin >> border;
            std::cout << "Color: ";
            std::string color;
            std::cin >> color;
            std::cout << CLEAR;
            std::cout << box({{"color",color},{"dimensions", {width, height}},{"border", border == "y"}});
            std::cout << "Press enter to continue";
            std::cin.ignore();
            std::cin.ignore();
        } else {
            std::cout << "\nInvalid choice";
            std::cout << "Press enter to continue";
            std::cin.ignore();
            std::cin.ignore();
            drawing = false;
        }
    }
}

int main() {
    //std::cout << CLEAR;
    //menu();
    //return 0;
    draw();

}