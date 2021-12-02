#include <iostream>
#include <fstream>

using ifstrm = std::ifstream;
using str = std::string;

int main() {
    ifstrm ifs("..\\day2.txt");
    str command;
    int value, depth = 0, hz = 0;
    while (ifs >> command >> value) {
        if (command == "forward") {
            hz += value;
        }
        else if (command == "down") {
            depth += value;
        }
        else if (command == "up") {
            depth -= value;
        }
    }
    std::cout << depth * hz;
    return 0;
}