//
//  part1.cpp
//  Day_4
//
//  Created by Fiona Stanley on 04/12/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, const char * argv[]) {
    std::ifstream input;
    input.open("input.txt");
    
    if (!input) {
        std::cerr << "Unable to open input file";
        return 1;
    }

    std::string line;
    std::vector<int> seatIDs;
    while (input >> line) {
        std::cout << line << std::endl;
        std::replace(line.begin(), line.end(), 'F', '0');
        std::replace(line.begin(), line.end(), 'B', '1');
        std::replace(line.begin(), line.end(), 'L', '0');
        std::replace(line.begin(), line.end(), 'R', '1');
        std::cout << line << std::endl;

        unsigned long row = std::bitset<8>(line.substr(0, 7)).to_ulong();
        unsigned long column = std::bitset<8>(line.substr(7, line.length())).to_ulong();

        std::cout << row << std::endl;
        std::cout << column << std::endl;

        seatIDs.push_back(row * 8 + column);
    }

    std::cout << *std::max_element(seatIDs.begin(), seatIDs.end()) << std::endl;

    input.close();

    return 0;
}
