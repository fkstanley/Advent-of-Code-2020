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

bool isValidBYR(std::string & byr) {
    if(byr.length() != 4 || std::stoi(byr) < 1920 || std::stoi(byr) > 2002) return false;
    return true;
}

bool isValidIYR(std::string iyr) {
    if(iyr.length() != 4 || std::stoi(iyr) < 2010 || std::stoi(iyr) > 2020) return false;
    return true;
}

bool isValidEYR(std::string eyr) {
    if(eyr.length() != 4 || std::stoi(eyr) < 2020 || std::stoi(eyr) > 2030) return false;
    return true;
}

bool isValidHGT(std::string hgt) {
    if(hgt.find("in") == std::string::npos && hgt.find("cm") == std::string::npos) return false;

    if(hgt.find("cm") != std::string::npos) {
        int index = hgt.find("cm");
        std::string height = hgt.substr(0, index);
        if (stoi(height) < 150 || stoi(height) > 193) return false;
    } else if (hgt.find("in") != std::string::npos) {
        int index = hgt.find("in");
        std::string height = hgt.substr(0, index);
        if (stoi(height) < 59 || stoi(height) > 76) return false;
    }
    return true;
}

bool isValidHCL(std::string hcl) {
    if(hcl.length() != 7 || hcl[0] != '#' || hcl.find_first_not_of("#0123456789abcdef") != std::string::npos) return false;
    return true;
}

bool isValidECL(std::string ecl) {
    if(ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth") return false;
    return true;
}

bool isValidPID(std::string pid) {
    if(pid.length() != 9 || pid.find_first_not_of("0123456789") != std::string::npos) return false;
    return true;
}

bool isValidPassport(std::map<std::string, std::string> & passport) {
    if (passport.count("byr") == 0) return false;
    else if (passport.count("iyr") == 0) return false;
    else if (passport.count("eyr") == 0) return false;
    else if (passport.count("hgt") == 0) return false;
    else if (passport.count("hcl") == 0) return false;
    else if (passport.count("ecl") == 0) return false;
    else if (passport.count("pid") == 0) return false;

    if(!isValidBYR(passport["byr"])) return false;
    if(!isValidIYR(passport["iyr"])) return false;
    if(!isValidEYR(passport["eyr"])) return false;
    if(!isValidHGT(passport["hgt"])) return false;
    if(!isValidHCL(passport["hcl"])) return false;
    if(!isValidECL(passport["ecl"])) return false;
    if(!isValidPID(passport["pid"])) return false;

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
