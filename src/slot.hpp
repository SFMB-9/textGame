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
            tag = savefile["savedata"]["tag"];
            playerName = savefile["savedata"]["player"]["name"];
            playerLocation = savefile["savedata"]["player"]["location"];
            slotColor = savefile["savedata"]["settings"]["slotColor"];
            savefile_stream.close();
        }
        json savefile;
        /*Methods*/
        void print(){
            std::cout << box({{"color", slotColor}, {"content",(playerName + "\n" + playerLocation)}});
        }
        void setPlayerName(std::string name){
            savefile["savedata"]["player"]["name"] = name;
            playerName = name;
        }
        void save(){
            std::ofstream savefile_stream("../storage/save"+std::to_string(tag)+".json");
            savefile_stream << savefile;
        }
    private:
        int tag;
        std::string playerName;
        std::string playerLocation;
        std::string slotColor;
        friend std::ostream& operator<<(std::ostream& os, const Slot& slot);
};
std::ostream& operator <<(std::ostream& os, const Slot& slot) {
    os << box({{"onNewLine",true},{"color", slot.slotColor},{"content",slot.playerName}});
    //os << box({{"color",slot.slotColor},{"content",(slot.playerName)},{"padding",{{"top",0},{"bottom",0},{"left",2},{"right",2}}}});
    return os;
}

#endif // _SLOT_HPP_