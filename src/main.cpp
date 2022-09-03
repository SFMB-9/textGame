#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include "anim.hpp"
#include "draw.hpp"
#include "inventory.hpp"
#include "json.hpp"
#include "player.hpp"
#include "render.hpp"
#include "slot.hpp"
#include "style.hpp"

using Json = nlohmann::json;

void eraseSlot(int slotTag) {
    std::string slot_path = "savefiles/save" + std::to_string(slotTag) + ".json";
    std::ofstream savefile_stream(slot_path);
    Json savefile;  

    savefile["savedata"]["tag"] = slotTag;
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
void newGame(Slot slot){
    // TODO: Event Class...?
    // Cue music
    /*Intro*/
    std::cout << CLEAR;
    std::cout << "The beginning of a new adventure...";
    std::cout << "\nWhat is your name?";
    std::cout << "\n> ";
    std::string name;
    std::cin >> name;
    std::cout << "Starring " << name << "!";
    //Set name
    slot.setPlayerName(name);
    std::cout << "Would you like to save your progress?";
    std::cout << "\n> ";
    std::string save;
    std::cin >> save;
    if (save == "yes") {
        slot.save();
    }
    std::cout << slot;
    //std::cout << CLEAR;
    loadGame(slot)
}

void loadGame(Slot slot){
    std::cout << "GAME EXITED";
    std::cout << "press enter to continue";
    std::cin.ignore();
}

int fileHandler(){
    bool inGame = true;
    while(inGame) {
        std::cout << CLEAR;
        std::cout << BOLD_CYAN << LOGO << "\nTHE GAME" << RESET;
        std::cout << box({{"offset",11},{"onNewLine",true},{"content","New Game "},{"doubleLine",true},{"padding",{{"top",0},{"bottom",0},{"left",5},{"right",5}}}});
        std::cout << box({{"offset",11},{"onNewLine",true},{"content","Load Game"},{"doubleLine",true},{"padding",{{"top",0},{"bottom",0},{"left",5},{"right",5}}}});
        std::cout << box({{"offset",11},{"onNewLine",true},{"content","Settings "},{"doubleLine",true},{"padding",{{"top",0},{"bottom",0},{"left",5},{"right",5}}}});
        std::cout << box({{"offset",11},{"onNewLine",true},{"content","  Quit   "},{"doubleLine",true},{"padding",{{"top",0},{"bottom",0},{"left",5},{"right",5}}}});
        std::cout << NEWLINE << NEWLINE << BOLD_CYAN << "Ver. 0.0.1                  Salvador Milanes Braniff" << RESET;
        std::cout << "\n> ";
        int choice;
        std::cin >> choice;
        bool isNewGame;
        if(choice == 1){
            isNewGame = true;
        } else if(choice == 2){
            isNewGame = false;
        } else if(choice == 3){
            std::cout << CLEAR;
            inGame = false;
            return -1;
        } else {
            std::cout << "\nInvalid Choice";
        }

        //Build slots vector
        std::vector<Slot> slots;
        for(int i = 1; i <= 3; i++){
            std::string slot_path = "../storage/save" + std::to_string(i) + ".json";
            std::ifstream savefile_stream(slot_path);
            Json savefile;
            savefile_stream >> savefile;
            slots.push_back(Slot(slot_path));
        }
        /*Selecting a slot*/
        std::cout << CLEAR;
        std::cout << "\nFILE SELECT";
        std::vector<std::string> slotBoxes;
        for(int i = 0; i < slots.size(); i++){
            std::stringstream st;
            //std::cout << slots[i]; //Debug
            st << slots[i];
            slotBoxes.push_back(st.str());
        }
        //Display horizontal menu
        std::cout << sideBySideBoxes(slotBoxes);
        std::cout << "\n> ";
        std::string slotChoice;
        std::cin >> slotChoice;
        Slot *selectedSlot;
        if(slotChoice == "1"){
            selectedSlot = &slots[0];
        } else if(slotChoice == "2"){
            selectedSlot = &slots[1];
        } else if(slotChoice == "3"){
            selectedSlot = &slots[2];
        } else if(slotChoice == "q") {
            std::cout << CLEAR;
            return -1;
        } else {
            std::cout << CLEAR;
            std::cout << "\nInvalid Choice";
            continue;
        }
        //std::cout << "\n" << selectedSlot->savefile["savedata"]["data"]; //Debug

        //Attempt new game
        if(isNewGame){
            if (selectedSlot->savefile["savedata"]["data"]){
                std::cout << "\nThis slot is already in use";
                    selectedSlot->print();
                std::cout << "\nDo you want to overwrite it? (y/n)";
                std::cout << "\n> ";
                std::string choice;
                std::cin >> choice;
                if(choice == "y"){
                    std::cout << "\nOverwriting...";
                    eraseSlot(stoi(slotChoice));

                } else {
                    std::cout << "\nAborting...";
                    continue;
                }
            }
            newGame(*selectedSlot);
        //Attempt load game
        } else {
            if (!selectedSlot->savefile["savedata"]["data"]){
                std::cout << "\nThis slot is empty";
                std::cout << "Would you like to start a new game? (y/n)";
                std::cout << "\n> ";
                std::string choice;
                std::cin >> choice;
                if(choice == "y"){
                    std::cout << "\nStarting new game...";
                    eraseSlot(stoi(slotChoice));
                    continue;
                } else {
                    std::cout << "\nAborting...";
                    continue;
                }
            }
        }
    }
    return 0;
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

int main() {
    std::cout << CLEAR;
    std::cout << "P r e s s   e n t e r   t o   p l a y . . ." << RESET;
    std::cin.get();
    bool play = true;
    while(play) {
        //animatedLogo();
        if(fileHandler() == -1) {
            play = false;
        }
        std::cout << BOLD <<"T h a n k s   f o r   p l a y i n g " << HEART << RESET;
    }

    return 0;
}