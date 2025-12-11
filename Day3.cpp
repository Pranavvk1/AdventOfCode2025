#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("AOC3.txt");
    std::string line = "";
    int sum = 0;

    while(std::getline(inputFile, line)) {
        int maxNum = 0;
        for(int i = 0; i < (int) line.length(); i++) {
            for (int j = i + 1; j < (int) line.length(); j++) {
                int tens = line.at(i) - 48; 
                int ones = line.at(j) - 48;

                int num = 10 * tens + ones;
                if(num > maxNum) {
                    maxNum = num;
                }
            }
        }
        sum += maxNum;
    }
    std::cout << sum;
}