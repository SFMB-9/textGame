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

std::string box(json style) {
    std::string box = "";
    /*Extract style*/
    bool onNewLine;
    if (style.find("onNewLine") != style.end())
        onNewLine = style["onNewLine"];
    int offset;
    if (style.find("offset") != style.end())
        offset = style["offset"];
    std::string color = (style.find("color") != style.end()) ? style["color"] : "";
    std::string content = (style.find("content") != style.end()) ? style["content"] : "";
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
    bool doubleLine;
    if (style.find("doubleLine") != style.end())
        doubleLine = style["doubleLine"];
    std::string borderColor = (style.find("borderColor") != style.end()) ? style["borderColor"] : "";
    std::string backgroundColor = (style.find("backgroundColor") != style.end()) ? style["backgroundColor"]: "";
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
        //std::cout << "Box is tall enough";
    } else {
        boxHeight = lines.size();
        //std::cout << "Box will be stretched vertically to fit content"; //debug
    }

    /*Build box*/
    color = colorcode(color);
    std::string offsetString = (offset > 0) ? std::string(offset, ' ') : "";
    std::string ifNewLine = (onNewLine) ? "\n" : "";
    std::string boxBody = "";
    int tempBoxHeight = boxHeight;
    //TOP OF BOX
    std::string boxTop = ifNewLine + offsetString + color + boxPieces[0] + std::string(boxWidth, boxPieces[1][0]) + boxPieces[2] + "\033[0m\n";
    //      Top padding
    for (int i = 0; i < padding[0]; i++) {
        boxBody += offsetString + color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
        tempBoxHeight--;
    }
    //BOX BODY - content
    for( auto line : lines ) {
        std::string boxLine = offsetString + color + boxPieces[3] + std::string(padding[3], ' ') + line + std::string(contentLength-(line.length()),' ') + std::string(padding[1], ' ') + boxPieces[5] + "\033[0m\n";
        boxBody += boxLine;
        tempBoxHeight--;
    }
    //      Bottom padding
    for (int i = 0; i < padding[2]; i++) {
        boxBody += offsetString + color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
        tempBoxHeight--;
    }
    //      By default, extra lines are placed after the bottom padding
    //      TODO: Add option to place extra lines before top padding or split them evenly
    for (int i = 0; i < tempBoxHeight; i++) {
        boxBody += offsetString + color + boxPieces[3] + std::string(boxWidth, ' ') + boxPieces[5] + "\033[0m\n";
    }
    //BOTTOM OF BOX
    std::string boxBottom = offsetString + color + boxPieces[6] + std::string(boxWidth, boxPieces[7][0]) + boxPieces[8] + "\033[0m";
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