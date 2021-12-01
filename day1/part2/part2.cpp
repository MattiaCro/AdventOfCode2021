#include <iostream>
#include <fstream>
#include <vector>

constexpr int WINDOW_SIZE = 3;

using ifsrm = std::ifstream;
using vi = std::vector<int>;

int main() {
	ifsrm ifs("day1.txt");
	int count = 0, curr;
	vi prevs(1, 0);
	while (ifs >> curr) {
		prevs.push_back(prevs.back() + curr);
	}
	for (int i = WINDOW_SIZE + 1; i < prevs.size(); ++i) {
		count += (prevs[i] - prevs[i - WINDOW_SIZE]) > (prevs[i - 1] - prevs[i - (WINDOW_SIZE + 1)]);
	}
	std::cout << count << std::endl;
	ifs.close();
	return 0;
}
