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
        std::cout << dir << offset << '\n';
        std::cout << "Before rotation " << pos << '\n';

        offset = offset % 100;
        if(dir == 'R') {
            pos += offset;
        } else {
            pos -= offset;
        }
        pos = (pos % 100 + 100) % 100;

        if(pos == 0) {
            count++;
        }
        std::cout << "After rotation " << pos << '\n';

    }
    std::cout << count;
}       