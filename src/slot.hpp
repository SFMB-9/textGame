#ifndef _SLOT_HPP_
#define _SLOT_HPP_

#include <iostream>
#include <fstream>

#include "json.hpp"
#include "render.hpp"
#include "special.hpp"

using json = nlohmann::json;

class Slot {
    public:
        /*Constructors*/
        Slot(std::string slot_path){ 
            std::ifstream savefile_stream(slot_path);
            savefile_stream >> savefile;
            data = savefile["savedata"]["data"];
            tag = savefile["savedata"]["tag"];
            playerName = savefile["savedata"]["player"]["name"];
            playerLocation = savefile["savedata"]["player"]["location"];
            slotColor = savefile["savedata"]["settings"]["slotColor"];
            savefile_stream.close();
        }
        json savefile;
        /*Methods*/
        void print(){
            std::cout << box({{"onNewLine", true},{"color", slotColor}, {"content",(playerName + "\n" + playerLocation)}, {"padding", {{"top",1},{"bottom",2},{"left",1},{"right",2}}}});
        }
        void setPlayerName(std::string name){
            playerName = name;
        }
        void save(){
            if(!data){
                data = true;
            }
            savefile["savedata"]["data"] = data;
            savefile["savedata"]["player"]["name"] = playerName;
            savefile["savedata"]["player"]["location"] = playerLocation;
            savefile["savedata"]["settings"]["slotColor"] = slotColor;
            std::ofstream savefile_stream("../storage/save"+std::to_string(tag)+".json");
            savefile_stream << savefile;
        }
        void erase(){
            savefile["savedata"]["tag"] = tag;
            savefile["savedata"]["data"] = false;
            savefile["savedata"]["player"]["name"] = "New game";
            savefile["savedata"]["player"]["location"] = "";
            savefile["savedata"]["player"]["inventory"] = {};
            savefile["savedata"]["settings"]["slotColor"] = "";
            savefile["savedata"]["gameStats"]["playTime"] = 0;
            savefile["savedata"]["gameStats"]["deaths"] = 0;
            savefile["savedata"]["gameStats"]["kills"] = 0;
            savefile["savedata"]["gameStats"]["completeQuests"] = 0;
            savefile["savedata"]["gameStats"]["failedQuests"] = 0;
            savefile["savedata"]["gameStats"]["completionPercentage"] = 0;
            std::ofstream savefile_stream("../storage/save"+std::to_string(tag)+".json");
            savefile_stream << savefile;
        }
    private:
        int tag;
        bool data;
        std::string playerName;
        std::string playerLocation;
        std::string slotColor;
        friend std::ostream& operator<<(std::ostream& os, const Slot& slot);
};
std::ostream& operator <<(std::ostream& os, const Slot& slot) {
    os << box({{"color",slot.slotColor},{"content",(slot.playerName)},{"padding",{{"top",0},{"bottom",0},{"left",2},{"right",2}}}});
    return os;
}

#endif // _SLOT_HPP_