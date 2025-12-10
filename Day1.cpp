#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("AOC1.txt");
    std::string rotation;
    int pos = 50;
    int count = 0;

    while (std::getline(inputFile, rotation)) {
        
        char dir = rotation.at(0);
        int offset = std::stoi(rotation.substr(1, std::string::npos));
        // std::cout << dir << offset << '\n';
        // std::cout << "Before rotation " << pos << '\n';

        for(int i = 0; i < offset; i++) {
            if(dir == 'R') {
                pos++;
            } else {
                pos--;
            }

            if(pos % 100 == 0) {
                count++;
            }
        }
        // std::cout << "After rotation " << pos << '\n';

    }
    std::cout << count;
}       