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

    if(passport["byr"].length() != 4 || std::stoi(passport["byr"]) < 1920 || std::stoi(passport["byr"]) > 2002) return false;
    if(passport["iyr"].length() != 4 || std::stoi(passport["iyr"]) < 2010 || std::stoi(passport["iyr"]) > 2020) return false;
    if(passport["eyr"].length() != 4 || std::stoi(passport["eyr"]) < 2020 || std::stoi(passport["eyr"]) > 2030) return false;

    if(passport["hgt"].find("in") == std::string::npos && passport["hgt"].find("cm") == std::string::npos) return false;
    if(passport["hgt"].find("cm") != std::string::npos) {
        int index = passport["hgt"].find("cm");
        std::string height = passport["hgt"].substr(0, index);
        if (stoi(height) < 150 || stoi(height) > 193) return false;
    } else if (passport["hgt"].find("in") != std::string::npos) {
        int index = passport["hgt"].find("in");
        std::string height = passport["hgt"].substr(0, index);
        if (stoi(height) < 59 || stoi(height) > 76) return false;
    }

    if(passport["hcl"].length() != 7 || passport["hcl"][0] != '#' || passport["hcl"].find_first_not_of("#0123456789abcdef") != std::string::npos) return false;

    if(passport["ecl"] != "amb" && passport["ecl"] != "blu" && passport["ecl"] != "brn" && passport["ecl"] != "gry" && passport["ecl"] != "grn" && passport["ecl"] != "hzl" && passport["ecl"] != "oth") return false;

    if(passport["pid"].length() != 9 || passport["pid"].find_first_not_of("0123456789") != std::string::npos) return false;

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
