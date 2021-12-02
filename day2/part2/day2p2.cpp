#include <iostream>
#include <fstream>

using ifstrm = std::ifstream;
using str = std::string;

int main() {
    ifstrm ifs("..\\day2.txt");
    str command;
    int value, depth = 0, hz = 0, aim = 0;
    while (ifs >> command >> value) {
        if (command == "forward") {
            hz += value;
            depth += aim * value;
        }
        else if (command == "down") {
            aim += value;
        }
        else if (command == "up") {
            aim -= value;
        }
    }
    std::cout << depth * hz;
    return 0;
}