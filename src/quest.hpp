#ifndef _QUEST_HPP_
#define _QUEST_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "flag.hpp"
#include "json.hpp"

using Json = nlohmann::json;

class Quest {
    public:
        Quest(std::string name, std::string desc);
        Quest(Json json) {
            std::cout << "Quest constructor called" << std::endl;
            std::cout << json << std::endl;
            name = (json.find("name") != json.end()) ? json["name"] : "Untitled Quest";
            desc = (json.find("description") != json.end()) ? json["description"] : "No description given";
            // for (auto flag : json["flags"]) {
            //     flags.push_back(Flag(flag));
            // }
        }
        std::string getName() { return name; }
        std::string getDescription() { return desc; }
        void setName(std::string name);
        void setDescription(std::string desc);
        // void addFlag(Flag flag);
        // void removeFlag(Flag flag);
        std::vector<Flag> getFlags();
        void setComplete();
        void setFail();

        void printForQuestLog(){
            std::cout << "========================" << std::endl;
            std::cout << "||" << name << std::endl << "||" << desc << std::endl;
            std::cout << "========================" << std::endl;
        }

    private:
        bool fail;
        bool isComplete();
        std::string name;
        std::string desc;
        std::vector<Flag> flags;
};

#endif // _QUEST_HPP_