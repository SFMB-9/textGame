#ifndef _FLAG_HPP_
#define _FLAG_HPP_

#include <string>
class Flag {
    public:
        Flag(std::string name, std::string desc);
        Flag(Json json) {
            name = json["name"];
            desc = json["desc"];
            isComplete = json["isComplete"];
        }
        std::string name;
        std::string desc;
        bool isComplete;
    private:
};

#endif // _FLAG_HPP_