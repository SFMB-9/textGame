#ifndef _RENDER_HPP_
#define _RENDER_HPP_

#include <iostream>
#include <string>

#include "style.hpp"
#include "special.hpp"

std::string box(std::string string) {
    std::string boxed = "\311"+ std::string(string.length(), '\315') + "\273\n\272" + string + "\272\n\310"+ std::string(string.length(), '\315') + "\274";
    return boxed;
}
std::string box(std::string string, int padding) {
    std::string padded = std::string(padding, ' ') + string + std::string(padding, ' ');
    std::string boxed = box(padded);
    return boxed;
}
std::string box(std::string string, int paddingLeft, int paddingRight) {
    std::string padded = std::string(paddingLeft, ' ') + string + std::string(paddingRight, ' ');
    std::string boxed = box(padded);
    return boxed;
}

std::string color(std::string string, std::string color) {
    if(color == "red") {
        return "\033[31m" + string + "\033[0m";
    } else if(color == "green") {
        return "\033[32m" + string + "\033[0m";
    } else if(color == "yellow") {
        return "\033[33m" + string + "\033[0m";
    } else if(color == "blue") {
        return "\033[34m" + string + "\033[0m";
    } else if(color == "magenta") {
        return "\033[35m" + string + "\033[0m";
    } else if(color == "cyan") {
        return "\033[36m" + string + "\033[0m";
    } else if(color == "white") {
        return "\033[37m" + string + "\033[0m";
    } else if(color == "black") {
        return "\033[30m" + string + "\033[0m";
    } else {
        return string;
    }
}

#endif // _RENDER_HPP_