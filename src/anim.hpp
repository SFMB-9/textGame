#ifndef _ANIM_HPP_
#define _ANIM_HPP_

#include <iostream>
#include <chrono>
#include <thread>

#include "special.hpp"
#include "style.hpp"

void animatedLogo(){
    std::cout << CLEAR;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << LOGO2;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << CLEAR;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << LOGO2;
    std::cout << CLEAR;
    std::cout << LOGO1;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << CLEAR;
    std::cout << LOGO2;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    int repeat = 2;
    while(repeat > 0){
        std::cout << CLEAR;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << LOGO2;
        std::cout << CLEAR;
        std::cout << LOGO1;
        std::cout << CLEAR;
        std::cout << LOGO;
        std::cout << BOLD_CYAN << LOGO;
        std::cout << CLEAR;
        std::cout << BOLD_CYAN << LOGO << RESET;
        repeat--;
    }
}

#endif // _ANIM_HPP_