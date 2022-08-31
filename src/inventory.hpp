#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <iostream>
#include "item.hpp"
#include "player.hpp"

class Inventory {
    public:
        void addItem(Item item);
        void removeItem(Item item);
        void printInventory();
        void printItem(Item item);
        void printItem(int index);
        Item getItem(int index);
        int getSize();
        void setSize(int size);
        int getWeight();
        void setWeight(int weight);
        int getMaxWeight();
        void setMaxWeight(int maxWeight);
        //void setPlayer(Player player);
        //Player getPlayer();

};

#endif // _INVENTORY_HPP_