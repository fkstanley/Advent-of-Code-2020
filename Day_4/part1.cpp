//
//  part1.cpp
//  Day_4
//
//  Created by Fiona Stanley on 04/12/2020.
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

bool isValidPassport(std::map<std::string, std::string> & passport) {
    if (passport.count("byr") == 0) return false;
    else if (passport.count("iyr") == 0) return false;
    else if (passport.count("eyr") == 0) return false;
    else if (passport.count("hgt") == 0) return false;
    else if (passport.count("hcl") == 0) return false;
    else if (passport.count("ecl") == 0) return false;
    else if (passport.count("pid") == 0) return false;

    return true;
}

int main(int argc, const char * argv[]) {
    std::ifstream input;
    input.open("input.txt");
    
    if (!input) {
        std::cerr << "Unable to open input file";
        return 1;
    }


    std::map<std::string, std::string> passport;
    int count = 0;
    for (std::string line; getline(input, line); ) {
        if (line.length() == 0) {
            if (isValidPassport(passport)) ++count;
            passport.clear();
            continue;
        }
        
        std::istringstream ss(line);
        std::string word;
        while (ss >> word) {
            std::string key = word.substr(0, 3);
            std::string value = word.substr(4, word.length());
            passport[key] = value;
        }
    }

    //Check final line as this isn't checked in loop
    if (isValidPassport(passport)) ++count;
    
    std::cout << count << std::endl;
    input.close();

    return 0;
}
