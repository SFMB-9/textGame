#ifndef _ROOM_HPP_
#define _ROOM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "flag.hpp"
#include "item.hpp"
#include "player.hpp"
#include "quest.hpp"

class Room {
    public:
        Room(std::string name, std::string desc);
        std::string getName();
        std::string getDescription();
        void setName(std::string name);
        void setDescription(std::string desc);
        void addFlag(Flag flag);
        void removeFlag(Flag flag);
        std::vector<Flag> getFlags();
        void addItem(Item item);
        void removeItem(Item item);
        std::vector<Item> getItems();
        void addQuest(Quest quest);
        void removeQuest(Quest quest);
        std::vector<Quest> getQuests();
        void addPlayer(Player player);
        void removePlayer(Player player);
        std::vector<Player> getPlayers();
    private:
        std::string name;
        std::string description;
        std::vector<Flag> flags;
        std::vector<Item> items;
        std::vector<Quest> quests;
        std::vector<Player> players;
};

#endif // _ROOM_HPP_