#ifndef _RENDER_HPP_
#define _RENDER_HPP_

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "json.hpp"
#include "style.hpp"
#include "special.hpp"

using json = nlohmann::json;

std::string colorcode(std::string color) {
    if(color == "red") {
        return "\033[31m";
    } else if(color == "green") {
        return "\033[32m";
    } else if(color == "yellow") {
        return "\033[33m";
    } else if(color == "blue") {
        return "\033[34m";
    } else if(color == "magenta") {
        return "\033[35m";
    } else if(color == "cyan") {
        return "\033[36m";
    } else if(color == "white") {
        return "\033[37m";
    } else if(color == "black") {
        return "\033[30m";
    } else {
        return "";
    }
}

std::string box(json style) {
    std::string box = "";
    /*Extract style*/
    std::string color = (style.find("color") != style.end()) ? style["color"] : "";
    std::string backgroundColor = (style.find("backgroundColor") != style.end()) ? style["backgroundColor"]: "";
    std::string content = (style.find("content") != style.end()) ? style["content"] : "";
    std::string borderColor = (style.find("borderColor") != style.end()) ? style["borderColor"] : "";
    bool doubleLine;
    if (style.find("doubleLine") != style.end())
        doubleLine = style["doubleLine"];
    std::vector<int> dimensions;
    std::cout << "MADE IT HERE";
    if (style.find("dimensions") != style.end()) {
        dimensions[0] = style["dimensions"][0];
        dimensions[1] = style["dimensions"][1];
        std::cout << "dimensions set";
    }
    std::cout << "MADE IT HERE";
    //std::vector<int> padding = (style.find("padding") != style.end()) ? style["padding"] : std::vector<int>{0, 0};
    
    std::vector<std::string> boxPieces = {
        BOX_ULC,BOX_HLINE,BOX_URC,
        BOX_VLINE, " " ,BOX_VLINE,
        BOX_LLC,BOX_HLINE,BOX_LRC
    };

    if(doubleLine) {
        boxPieces = {
            BOX2_ULC,BOX2_HLINE,BOX2_URC,
            BOX2_VLINE,  " " ,BOX2_VLINE,
            BOX2_LLC,BOX2_HLINE,BOX2_LRC
        };
    }

    /*Calculate box size*/
    std::stringstream ss(content);
    std::string line;
    std::vector<std::string> lines;
    int contentLength = content.length();

    if (content != "") {
        int longestLine = 0;
        while (std::getline(ss, line, '\n')) {
            lines.push_back(line);
            if (line.length() > longestLine) {
                longestLine = line.length();
            }
        }
        contentLength = longestLine;
    }

    int boxWidth = contentLength; //+ padding[1] + padding[3];

    /*Build box*/
    color = colorcode(color);
    std::string boxTop = color + boxPieces[0] + std::string(boxWidth, boxPieces[1][0]) + boxPieces[2] + "\033[0m\n";
    std::string boxBody = "";
    for( auto line : lines ) {
        std::string boxLine = color + boxPieces[3] /*+ std::string(padding[3], ' ')*/ + line + std::string(contentLength-(line.length()),' ')/*+ std::string(padding[1], ' ')*/ + boxPieces[5] + "\033[0m\n";
        boxBody += boxLine;
    }
    std::string boxBottom = color + boxPieces[6] + std::string(boxWidth, boxPieces[7][0]) + boxPieces[8] + "\033[0m\n";
    box = boxTop + boxBody + boxBottom;
    
    return box;
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

void print(std::string string){
    std::cout << string << "\n";
}

#endif // _RENDER_HPP_