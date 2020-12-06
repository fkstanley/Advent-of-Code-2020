//
//  part1.cpp
//  Day_4
//
//  Created by Fiona Stanley on 04/12/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <sstream>

int main(int argc, const char * argv[]) {
    std::ifstream input;
    input.open("input.txt");
    
    if (!input) {
        std::cerr << "Unable to open input file";
        return 1;
    }

    std::array<char, 26> union_characters;
    union_characters.fill(0);
    int count = 0;
    std::string line;
    while(std::getline(input, line)) {
        if (line == "") {
            for (int i = 0; i < 26; ++i) {
                if (union_characters[i] > 0) ++count;
            }
            union_characters.fill(0);
        }
        for (int i = 0; i < line.size(); ++i) union_characters[int(line[i]) - 97]++;
    }

    // Final check as last line isn't included in loop
    for (int i = 0; i < 26; ++i) {
        if (union_characters[i] > 0) ++count;
    }

    std::cout << count << std::endl;

    input.close();

    return 0;
}
