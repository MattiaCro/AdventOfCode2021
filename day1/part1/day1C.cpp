#include <stdio.h>

void solve() {
	FILE* input = fopen("day1.", "rt");
	if (!input) {
		perror("File not found");
		exit(1);
	}
	int prev, curr, counter = 0;
	if (fscanf(input, "%d\n", &prev) != 1) {
		perror("File not read correctly");
		exit(1);
	}
	while (fscanf(input, "%d\n", &succ)) {
		counter += (curr > prev);
		prev = curr;
	}
	printf("%d", counter);
}

int main() {
	solve();
	return 1;
}
