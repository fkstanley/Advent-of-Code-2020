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
        std::cout << numbers << " " << character[0] << " " << pattern << std::endl;
        
        std::istringstream f(numbers);
        std::string s;
        int numbers[2];
        int index = 0;
        while (std::getline(f, s, '-')) {
            numbers[index] = std::stoi(s);
            ++index;
        }

        size_t n = std::count(pattern.begin(), pattern.end(), character[0]);
        std::cout << n << std::endl;
        if (n >= numbers[0] && n <= numbers[1]) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    input.close();

    return 0;
}
