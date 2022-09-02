#ifndef _DRAW_HPP_
#define _DRAW_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"
#include "render.hpp"
#include "style.hpp"
#include "special.hpp"

void draw(){
    bool drawing = true;
    while(drawing){
        std::cout << CLEAR;
        std::cout << "1. Box of a given word and color";
        std::cout << "\n2. Box of a given color and size";
        std::cout << "\n3. Box factory (Experimental)";
        std::cout << "\n> ";
        int command;
        std::cin >> command;
        if(command == 1){
            std::cout << "\nWord: ";
            std::string text;
            std::cin >> text;
            std::cout << "\nColor: ";
            std::string color;
            std::cin >> color;
            std::cout << CLEAR;
            std::cout << box({{"content", text},{"color", color}});
            std::cout << "Press enter to continue... ";
            std::cin.ignore();
            std::cin.ignore();
        } else if(command == 2){
            std::cout << "\nColor: ";
            std::string color;
            std::cin >> color;
            std::cout << "\nWidth: ";
            int width;
            std::cin >> width;
            std::cout << "Height: ";
            int height;
            std::cin >> height;
            std::cout << CLEAR;
            std::cout << box({{"color",color},{"dimensions", {{"width", width},{"height", height}}}, {"doubleLine", true}});
            std::cout << "Press enter to continue... ";
            std::cin.ignore();
            std::cin.ignore();
        } else if(command == 3){
            std::cout << "\nWidth: ";
            int width;
            std::cin >> width;
            std::cout << "Height: ";
            int height;
            std::cin >> height;
            std::cout << "Border (y/n): ";
            std::string border;
            std::cin >> border;
            std::cout << "Color: ";
            std::string color;
            std::cin >> color;
            std::cout << CLEAR;
            std::cout << box({{"color",color},{"dimensions", {{"width",width},{"height", height}}},{"doubleLine", border == "y"}});
            std::cout << "Press enter to continue... ";
            std::cin.ignore();
            std::cin.ignore();
        } else {
            std::cout << "\nInvalid choice";
            std::cout << "\nPress enter to continue... ";
            std::cin.ignore();
            std::cin.ignore();
            drawing = false;
        }
    }
}

#endif // _DRAW_HPP_