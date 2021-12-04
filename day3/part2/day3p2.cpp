#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

using ifstr = std::ifstream;
using str = std::string;
using vs = std::vector<str>;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

str solve(vs binaries, int pos, std::function<char(const int&, const int&)> criteria) {
    int ones = 0;
    int zeroes = 0;
    if (binaries.size() == 1) {
        return binaries[0];
    }
    for (const auto& i : binaries) {
        if (i[pos] == '1') {
            ++ones;
        }
        else {
            ++zeroes;
        }
    }
    vs newBins;
    char lookFor = criteria(ones, zeroes);
    for (const auto& i : binaries) {
        if (i[pos] == lookFor) {
            newBins.push_back(i);
        }
    }
    for (const auto& i : newBins) {
        std::cout << i << std::endl;
    }
    std::cout << "\n\n";
    return solve(newBins, pos + 1, criteria);
}

int main() {
    ifstr ifs("..\\day3.txt");
    int i = 0;
    vs binaries;
    str hold;
    while (ifs >> hold) {
        binaries.push_back(hold);
    }
    int o2 = stoi(solve(binaries, 0, [=] (const int& a, const int& b) { return a >= b ? '1' : '0'; }), 0 , 2);
    int co2 = stoi(solve(binaries, 0, [=] (const int& a, const int& b) { return a < b ? '1' : '0'; }), 0, 2);
    std::cout << o2 * co2 << std::endl;
    ifs.close();
    return 0;
}