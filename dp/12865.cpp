#include<stdio.h>
#include<algorithm>
using namespace std;

int N, K;
int W[101], V[101];
int bp[101][100001];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= W[i]) {
				bp[i][j] = max(bp[i - 1][j], bp[i - 1][j - W[i]] + V[i]);
			}
			else
				bp[i][j] = bp[i - 1][j];
		}
	}
	printf("%d", bp[N][K]);

	return 0;
}