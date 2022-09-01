#ifndef _SLOT_HPP_
#define _SLOT_HPP_

#include <iostream>
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;

class Slot {
    public:
        Slot(std::string slot_path){ //Constructor
            std::ifstream savefile_stream(slot_path);
            savefile_stream >> savefile;
        }
    private:
        json savefile;
        friend std::ostream& operator<<(std::ostream& os, const Slot& slot);
};
std::ostream& operator <<(std::ostream& os, const Slot& slot) {
    os << std::setw(2) << slot.savefile;
    return os;
}

#endif // _SLOT_HPP_