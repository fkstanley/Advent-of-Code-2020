//
//  main.cpp
//  Day_1
//
//  Created by Fiona Stanley on 01/12/2020.
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
    
    std::vector<int> input_array;
    int x;
    while (input >> x) {
        input_array.push_back(x);
    }
    
    int value1 = 0, value2 = 0, value3 = 0;
    for (int x : input_array) {
        for (int y : input_array) {
            for (int z : input_array) {
                if (x + y + z == 2020) {
                    value1 = x;
                    value2 = y;
                    value3 = z;
                    break;
                }
            }
        }
    }
    
    std::cout << value1 * value2 * value3 << std::endl;
    input.close();

    return 0;
}
