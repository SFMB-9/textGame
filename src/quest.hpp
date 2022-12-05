#ifndef _QUEST_HPP_
#define _QUEST_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "event.hpp"
#include "flag.hpp"
#include "json.hpp"

using Json = nlohmann::json;

class Quest {
    public:
        Quest(std::string name, std::string desc);
        Quest(Slot slot, Json json) {
            std::cout << "Quest constructor called" << std::endl;
            // std::cout << json << std::endl;
            // name = (json.find("name") != json.end()) ? json["name"] : "Untitled Quest";
            // desc = (json.find("description") != json.end()) ? json["description"] : "No description given";
            // for (auto event : json["events"]) {
            //     events.push_back(Event(event, slot));
            // }
        }
        void printForQuestLog(){
            std::cout << "========================" << std::endl;
            std::cout << "||" << name << std::endl << "||" << desc << std::endl;
            std::cout << "========================" << std::endl;
        }
        void run(){
            //Iterate through events and execute them
            for (auto event : events) {
                event.run();
            }
        }

    private:
        Slot slot;
        bool fail;
        bool isComplete();
        std::string name;
        std::string desc;
        std::vector<Event> events;
        std::vector<Flag> flags;
};

#endif // _QUEST_HPP_