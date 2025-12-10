#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("AOC2.txt");
    char ch;
    long long int start;
    long long int end;
    std::string string;
    long long int sum = 0;
    bool endParse = false;

    while(inputFile.get(ch)) {
        if(ch == '-') {
            start = std::stoll(string);
            string = "";
            continue;
        } 
        if(ch == ',') {
            end = std::stoll(string);
            string = "";
            endParse = true;
            continue;
        }
        string.push_back(ch);
        if(endParse) {
            for(long long int i = start; i <= end; i = i + 1) {
                bool isInvalid = true;
                std::string id = std::to_string(i);
                for (int j = 2; j <= (int) id.length(); j++) {         // Divide the string j times
                    if(id.length() % j == 0) {                         // H as to be divisible by j
                        std::string baseStr = id.substr(0, id.length() / j);
                        bool isInPattern = false;   
                        for(int k = 1; k < j; k++) {                   // iterate through string to see if pattern fits
                            if(id.substr(k * id.length() / j, id.length() / j) != baseStr) {
                                isInPattern = true;                      // doesnt fit in pattern
                            }
                        }
                        if(!isInPattern) isInvalid = false;
                        if(!isInvalid) break;                               // if we find that it fits the pattern for any value of j, we should not check any other values of j
                    }
                }
                if(!isInvalid) { 
                    sum += i;
                }
            }
            endParse = false;
        }
    }
    std::cout << sum;
}