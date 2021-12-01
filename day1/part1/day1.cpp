#include <iostream>
#include <fstream>

using ifsrm = std::ifstream;

int main() {
	ifsrm ifs("day1.txt");
	int count = 0, curr, prev;
	ifs >> prev;
	while (ifs >> curr) {
		count += (curr > prev);
		prev = curr;
	}
	std::cout << count << std::endl;
	return 0;
}
