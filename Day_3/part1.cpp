//
//  main.cpp
//  Day_2
//
//  Created by Fiona Stanley on 02/12/2020.
//

#include <iostream>
#include <fstream>
#include <vector>

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

    int sizeOfLine = map[0].length();
    int x = 0, count = 0;
    for (std::string line : map) {
        if (line[x] == '#') ++count;
        x = (x + 3) % sizeOfLine;
    }

    std::cout << count << std::endl;
    input.close();

    return 0;
}
