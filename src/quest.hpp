#ifndef _QUEST_HPP_
#define _QUEST_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "flag.hpp"

class Quest {
    public:
        Quest(std::string name, std::string desc);
        std::string getName();
        std::string getDescription();
        void setName(std::string name);
        void setDescription(std::string desc);
        void addFlag(Flag flag);
        void removeFlag(Flag flag);
        std::vector<Flag> getFlags();
        void setComplete();
        void setFail();

    private:
        bool fail;
        bool isComplete();
        std::string name;
        std::string desc;
        std::vector<Flag> flags;
};

#endif // _QUEST_HPP_