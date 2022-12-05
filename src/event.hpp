#ifndef _EVENT_HPP_
#define _EVENT_HPP_

#include <iostream>

#include "json.hpp"
#include "slot.hpp"
#include "style.hpp"

using Json = nlohmann::json;

class Event {
    public:
        Event(std::string name, std::string desc);
        Event(Json json, Slot slot) {
            //std::cout << "Event constructor called" << std::endl;
            // Set slot
            this->json = json;
            this->slot = slot;
        }
        void run(){
            //Iterate through event content
            std::cout << "--------\n";
            for (auto task : json) {
                terminal_task((task.find("terminal") != task.end()) ? task["terminal"] : "default");
                prompt_task((task.find("prompt") != task.end()) ? task["prompt"] : "");
                dialog_task((task.find("dialog") != task.end()) ? task["dialog"] : "");
                waiter_task((task.find("waiter") != task.end()) ? task["waiter"] : "");
                render_task((task.find("render") != task.end()) ? task["render"] : "");
                
            }
            std::cout << "--------\n";
        }
        void terminal_task(std::string terminal){
            if(terminal == "CLEAR"){
                std::cout << "terminal_task: CLEAR \n";
                //std::cout << CLEAR;
            } else if(terminal == "CLEAR_LAST"){
                std::cout << "terminal_task: CLEAR_LAST\n";
                //std::cout << CLEAR_LAST;
            } else {
                return;
            }
        }
        void dialog_task(std::string dialog){
            if(dialog == ""){
                return;
            } else {
                std::cout << "dialog_task: " << dialog << std::endl;
            }
        }
        void prompt_task(Json prompt){
            std::string query_string = (prompt.find("query") != prompt.end()) ? prompt["query"] : "default";

            if(prompt == ""){
                return;
            } else {
                std::cout << "prompt_task: " << prompt << std::endl;
            }
        }
        void waiter_task(Json waiter){
            if(waiter == ""){
                return;
            } else {
                std::cout << "waiter_task: " << waiter << std::endl;
            }
        }
        void render_task(Json render){
            if(render == ""){
                return;
            } else {
                std::cout << "render_task: " << render << std::endl;
            }
        }
    private:
        Json json;
        Slot slot;
};
#endif // _EVENT_HPP_