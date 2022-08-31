#ifndef _SLOT_HPP_
#define _SLOT_HPP_

#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

class Slot {
    private:
        json savefile;
    public:
        Slot(json savefile_){
            savefile = savefile_;
        }
        friend std::ostream& operator<<(std::ostream& os, const Slot& slot);
};
std::ostream& operator <<(std::ostream& os, const Slot& slot);

#endif // _SLOT_HPP_