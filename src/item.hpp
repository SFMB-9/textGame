#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>

class Item {
    public:
        Item(std::string name, std::string description, int weight);
        std::string getName();
        std::string getDescription();
        /*Getters and setters for weight*/
        int getWeight();
        void setWeight(int weight);
        
        void setName(std::string name);
        void setDescription(std::string description);

    private:
        std::string name;
        std::string description;
        int weight;

};

#endif // _ITEM_HPP_