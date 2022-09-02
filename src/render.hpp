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
    if (style.find("dimensions") != style.end()) { 
        dimensions.push_back(style["dimensions"]["width"]);
        dimensions.push_back(style["dimensions"]["height"]);
        //std::cout << "dimensions set"; //debug
    } else {
        dimensions.push_back(0);
        dimensions.push_back(0);
        //std::cout << "dimensions not set"; //debug
    }

    std::vector<int> padding;
    if (style.find("padding") != style.end()) {
        padding.push_back(style["padding"]["top"]);
        padding.push_back(style["padding"]["right"]);
        padding.push_back(style["padding"]["bottom"]);
        padding.push_back(style["padding"]["left"]);
        //std::cout << "padding set"; //debug
    } else {
        padding.push_back(0);
        padding.push_back(0);
        padding.push_back(0);
        padding.push_back(0);
        //std::cout << "padding not set"; //debug
    }

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

    int boxWidth;
    if(dimensions[0] >= (contentLength+padding[1]+padding[3])) {
        boxWidth = dimensions[0]-padding[1]-padding[3];
        //std::cout << "Box is wide enough"; //debug
    } else {
        boxWidth = contentLength+padding[1]+padding[3];
        //std::cout << "Box will be stretched horizontally to fit content"; //debug
    }

    int boxHeight;
    if(dimensions[1] >= (lines.size()+padding[0]+padding[2])) {
        boxHeight = dimensions[1]-padding[0]-padding[2];
        std::cout << "Box is tall enough";
    } else {
        boxHeight = lines.size();
        //std::cout << "Box will be stretched vertically to fit content"; //debug
    }

    /*Build box*/
    color = colorcode(color);
    std::string boxTop = "\n"+color + boxPieces[0] + std::string(boxWidth, boxPieces[1][0]) + boxPieces[2] + "\033[0m\n";
    std::string boxBody = "";
    int tempBoxHeight = boxHeight;
    //Top padding
    for (int i = 0; i < padding[0]; i++) {
        boxBody += color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
        tempBoxHeight--;
    }
    //Content
    for( auto line : lines ) {
        std::string boxLine = color + boxPieces[3] + std::string(padding[3], ' ') + line + std::string(contentLength-(line.length()),' ') + std::string(padding[1], ' ') + boxPieces[5] + "\033[0m\n";
        boxBody += boxLine;
        tempBoxHeight--;
    }
    //Bottom padding
    for (int i = 0; i < padding[2]; i++) {
        boxBody += color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
        tempBoxHeight--;
    }
    //By default, extra lines are placed after the bottom padding
    //TODO: Add option to place extra lines before top padding or split them evenly
    for (int i = 0; i < tempBoxHeight; i++) {
        boxBody += color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
    }
    std::string boxBottom = color + boxPieces[6] + std::string(boxWidth, boxPieces[7][0]) + boxPieces[8] + "\033[0m";
    box = boxTop + boxBody + boxBottom;
    
    return box;
}

std::string sideBySideBoxes(std::vector<std::string> boxes) {
    std::string sideBySide = "";
    //Slicing boxes into lines
    std::vector<std::vector<std::string>> slicedBoxes;
    for (auto box : boxes) {
        std::vector<std::string> slicedBox;
        std::stringstream ss(box);
        std::string line;
        while (std::getline(ss, line, '\n')) {
            slicedBox.push_back(line);
        }
        slicedBoxes.push_back(slicedBox);
    }
    //Joining boxes by line
    for (int i = 0; i < slicedBoxes[0].size(); i++) {
        for (auto slicedBox : slicedBoxes) {
            sideBySide += slicedBox[i];
        }
        sideBySide += "\n";
    }
    return sideBySide;
}


void print(std::string string){
    std::cout << string << "\n";
}

#endif // _RENDER_HPP_