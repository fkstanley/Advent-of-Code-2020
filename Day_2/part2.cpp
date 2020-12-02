//
//  main.cpp
//  Day_2
//
//  Created by Fiona Stanley on 02/12/2020.
//

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[]) {
    std::ifstream input;
    input.open("input.txt");
    
    if (!input) {
        std::cerr << "Unable to open input file";
        return 1;
    }
    
    int count = 0;
    std::string numbers, character, pattern;
    while (input >> numbers >> character >> pattern) {
        std::istringstream f(numbers);
        std::string s;
        int numbers[2];
        int index = 0;
        while (std::getline(f, s, '-')) {
            numbers[index] = std::stoi(s) - 1;
            ++index;
        }

        bool check1 = character[0] == pattern[numbers[0]];
        bool check2 = character[0] == pattern[numbers[1]];
        if (check1 ^ check2) {
            ++count;
        }
        
    }

    std::cout << count << std::endl;
    input.close();

    return 0;
}
