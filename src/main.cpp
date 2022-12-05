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
#include "quest.hpp"
#include "render.hpp"
#include "slot.hpp"
#include "style.hpp"

using Json = nlohmann::json;

std::string smartInput(std::string query, bool caseSensitive){
    std::string input;
    std::cout << NEWLINE << query;
    std::cin >> input;
    if(caseSensitive){
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    }
    return input;
}

std::vector<Quest> buildQuestQueue(Slot slot){
    std::vector<Quest> questQueue;
    std::ifstream questDataStream("data/quests.json");
    Json questData;
    questDataStream >> questData;
    for (Json quest : questData) {
        std::cout << "Building quest: " << quest["name"] << std::endl;
        std::cin.get();
    }
    return questQueue;
}

void loadGame(Slot slot){
    //std::cout << CLEAR;
    std::cout << "GAME ESCAPED";
    std::cout << "press enter to continue";
    std::cin.get();
    //Build quest queue
    std::vector<Quest> questQueue = buildQuestQueue(slot);
    // Iterate through quest queue and run each quest's events
    for (auto quest : questQueue) {
        quest.run();
        // quest.printForQuestLog();
    }
}

/*New Game*/
void newGame(Slot slot){
    // TODO: Event Class...?
    // Cue music
    /*Intro*/
    std::cin.get();
    // std::cout << CLEAR;
    // std::cout << "The beginning of a new adventure...";
    // std::cout << "\nWhat is your name?\n> ";
    // std::string name;
    // std::cin.ignore();
    // std::getline(std::cin,name);
    // std::cout << CLEAR_LAST;
    // std::cout << CLEAR_LAST;
    // std::cout << "Starring " << GREEN << name << RESET << "!";
    // //Set name
    // slot.setPlayerName(name);
    // std::string save = smartInput("Would you like to save your progress? (Yeahhh... no autosave.. Sorry)\n> ", true);
    // if (save == "yes"||save == "y"||save == "1") {
    //     slot.save();
    // }
    // std::cout << "Slot created!";
    // std::cout << NEWLINE << slot;
    // std::cin.get();
    loadGame(slot);
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
            std::cout << "Settings";
        } else if(choice == 4){
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
            // std::cout << slots[i]; //Debug
            st << slots[i];
            slotBoxes.push_back(st.str());
        }
        //Display horizontal menu
        std::cout << NEWLINE << sideBySideBoxes(slotBoxes);
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
            continue;
        } else {
            std::cout << CLEAR;
            std::cout << "\nInvalid Choice";
            continue;
        }
        /*Slot selected*/
        //Attempt new game
        if(isNewGame){
            if (selectedSlot->savefile["savedata"]["data"]){
                std::cout << "\nThis slot is already in use";
                    selectedSlot->print();
                std::string choice = smartInput("Do you want to overwrite it? (y/n)\n> ", true);
                if(choice == "y"||choice == "yes"||choice == "1"){
                    std::cout << "\nOverwriting...";

                } else {
                    std::cout << "\nAborting...";
                    continue;
                }
            }
            selectedSlot->erase(); //Erase slot (potentially corrupted) tabula rasa
            newGame(*selectedSlot);
        //Attempt load game
        } else {
            if (!selectedSlot->savefile["savedata"]["data"]){
                std::cout << "\nThis slot is empty";
                std::cout << "\nWould you like to start a new game? " << YELLOW << "(y/n)" << RESET;
                std::string choice = smartInput("\n> ", true);
                if(choice == "y"){
                    std::cout << "\nStarting new game...";
                    selectedSlot->erase();
                    newGame(*selectedSlot);
                    continue;
                } else {
                    std::cout << "\nAborting...";
                    continue;
                }
            } else {
                loadGame(*selectedSlot);
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
        // animatedLogo();
        if(fileHandler() == -1) {
            play = false;
        }
        std::cin.get();
        std::cout <<"T h a n k s   f o r   p l a y i n g " << BOLD_RED << HEART << RESET;
        play = false;
    }

    return 0;
}