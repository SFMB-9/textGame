#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "draw.hpp"
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
    std::vector<Slot> slots;
    for(int i = 1; i <= 3; i++){
        std::string slot_path = "savefiles/save" + std::to_string(i) + ".json";
        std::ifstream savefile_stream(slot_path);
        Json savefile;
        savefile_stream >> savefile;
        if(savefile["savedata"]["data"] == false){
            slots.push_back(Slot(slot_path));
        }
    }
    std::cout << CLEAR;
    std::cout << "\nSelect a save slot:";
    std::vector<std::string> slotBoxes;
    for(int i = 0; i < slots.size(); i++){
        std::stringstream st;
        st << slots[i];
        slotBoxes.push_back(st.str());
    }
    //Horizontal menu
    std::cout << sideBySideBoxes(slotBoxes);
    std::cout << "\n> ";
    int slotChoice;
    std::cin >> slotChoice;
    Slot *selectedSlot;
    if(slotChoice == 1){
        selectedSlot = &slots[0];
    } else if(slotChoice == 2){
        selectedSlot = &slots[1];
    } else if(slotChoice == 3){
        selectedSlot = &slots[2];
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
int main() {
    std::cout << CLEAR;
    menu();
    return 0;
}