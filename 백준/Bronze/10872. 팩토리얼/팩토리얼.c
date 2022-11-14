#include <stdio.h>
int N;

int recur(int N) {
	if (N == 0)
		return 1;
	return N * recur(N - 1);
}
int main() {
	scanf("%d", &N);
	printf("%d", recur(N));
}