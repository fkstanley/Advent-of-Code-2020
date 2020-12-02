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
    std::string min_max, character, password;
    while (input >> min_max >> character >> password) {
        std::istringstream f(min_max);
        std::string s;
        int min_max[2];
        int index = 0;
        while (std::getline(f, s, '-')) {
            min_max[index] = std::stoi(s);
            ++index;
        }

        size_t n = std::count(password.begin(), password.end(), character[0]);
        if (n >= min_max[0] && n <= min_max[1]) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    input.close();

    return 0;
}
