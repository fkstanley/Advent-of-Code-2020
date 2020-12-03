//
//  main.cpp
//  Day_2
//
//  Created by Fiona Stanley on 02/12/2020.
//

#include <iostream>
#include <fstream>
#include <vector>

long traverseSlope(std::vector<std::string> map, int x_step, int y_step) {
    int sizeOfLine = map[0].length();
    int x = 0, y = 0;
    long count = 0;

    while (y < map.size()) {
        if (map[y][x] == '#') ++ count;
        x = (x + x_step) % sizeOfLine;
        y = y + y_step;
    }

    return count;
}

int main(int argc, const char * argv[]) {
    std::ifstream input;
    input.open("input.txt");
    
    if (!input) {
        std::cerr << "Unable to open input file";
        return 1;
    }
    
    std::string line;
    std::vector<std::string> map;
    while (input >> line) {
        map.push_back(line);
    }


    std::cout << traverseSlope(map, 1, 1) *
        traverseSlope(map, 3, 1) *
        traverseSlope(map, 5, 1) *
        traverseSlope(map, 7, 1) *
        traverseSlope(map, 1, 2) << std::endl;

    input.close();

    return 0;
}
