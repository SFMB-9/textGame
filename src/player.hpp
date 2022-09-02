#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "inventory.hpp"
#include "slot.hpp"

class Player {
    public:
        /*Constructors*/
        Player(Slot slot){
            name = slot.savefile["name"];
        }
    private:
        std::string name;
        float hp;
        float max_hp;
        //Inventory inventory;
};

#endif // _PLAYER_HPP_