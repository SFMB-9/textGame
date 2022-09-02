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
            playerName = savefile["savedata"]["player"]["name"];
            playerLocation = savefile["savedata"]["player"]["location"];
            slotColor = savefile["savedata"]["settings"]["slotColor"];
        }
        json savefile;
        /*Methods*/
        void print(){
            std::cout << "\n";
        }
    private:
        friend std::ostream& operator<<(std::ostream& os, const Slot& slot);
        std::string playerName;
        std::string playerLocation;
        std::string slotColor;
};
std::ostream& operator <<(std::ostream& os, const Slot& slot) {
    os << box({{"color",slot.slotColor},{"content",(slot.playerName)},{"padding",{{"top",0},{"bottom",0},{"left",2},{"right",2}}}});
    return os;
}

#endif // _SLOT_HPP_