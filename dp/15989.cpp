#include<stdio.h>

using namespace std;

int T, now;
int dp[10000];

void init() {
	for (int i = 0; i < 10000; i++)
		dp[i] = 0;
}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		scanf("%d", &now);
		init();
		dp[0] = 1;
		for (int a = 1; a <= 3; a++) {
			for (int b = 1; b <= now; b++)
				dp[b] += dp[b - a];
		}

		printf("%d \n", dp[now]);
	}

	return 0;
}