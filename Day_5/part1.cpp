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
        std::replace(line.begin(), line.end(), 'F', '0');
        std::replace(line.begin(), line.end(), 'B', '1');
        std::replace(line.begin(), line.end(), 'L', '0');
        std::replace(line.begin(), line.end(), 'R', '1');

        unsigned long row = std::bitset<8>(line.substr(0, 7)).to_ulong();
        unsigned long column = std::bitset<8>(line.substr(7, line.length())).to_ulong();

        seatIDs.push_back(row * 8 + column);
    }

    std::sort(seatIDs.begin(), seatIDs.end());

    int mySeat = 0;
    for (int i = 1; i < seatIDs.size(); i ++) {
        if (seatIDs[i] - 2 == seatIDs[i - 1]) mySeat = seatIDs[i] - 1;
    }

    std::cout << mySeat << std::endl;

    input.close();

    return 0;
}
