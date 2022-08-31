#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "inventory.hpp"

class Player {
    public:
        std::string name;
    private:
        float hp;
        float max_hp;
        Inventory inv;
};

#endif // _PLAYER_HPP_