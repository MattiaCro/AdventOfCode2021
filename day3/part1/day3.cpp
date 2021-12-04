#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using ifstr = std::ifstream;
using str = std::string;
using vs = std::vector<str>;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

inline int pow2(int n) {
    return (1 << n);
}

int main() {
    ifstr ifs("..\\day3.txt");
    int i = 0;
    str hold;
    int fileLen = 0;
    vi counters;
    if (ifs >> hold) {
        counters.resize(hold.length());
        for (int i = 0; i < 12; ++i) {
            if (hold[i] == '1') {
                ++counters[i];
            }
        }
        ++fileLen;
    }
    while (ifs >> hold) {
        for (int i = 0; i < 12; ++i) {
            if (hold[i] == '1') {
                ++counters[i];
            }
        }
        ++fileLen;
    }
    int gamma = 0, epsilon = 0;
    for (int i = 0; i < counters.size(); ++i) {
        if (counters[i] > fileLen / 2) {
            gamma += pow2(counters.size() - (i + 1));
        }
        else {
            epsilon += pow2(counters.size() - (i + 1));
        }
    }
    std::cout << gamma * epsilon;
    ifs.close();
    return 0;
}