#include<stdio.h>
#define MOD 1000000007

using namespace std;

int N, K;

long long power(long long a, long long b) {
	if (b == 0)
		return 1;
	if (b % 2 != 0)
		return (power(a, b - 1) * a) % MOD;
	long long half = power(a, b / 2) % MOD;

	return (half * half) % MOD;
}

int main() {

	scanf("%d %d", &N, &K);

	long long A = 1, B = 1;

	for (int i = 1; i <= N; i++) {
		A *= i;
		A %= MOD;
	} // n! 

	for (int i = 1; i <= K; i++) {
		B *= i;
		B %= MOD;
	} // k!

	for (int i = 1; i <= N - K; i++) {
		B *= i;
		B %= MOD;
	} // (n-k)!

	long long C = power(B, MOD - 2);
	long long answer = A * C;
	answer %= MOD;

	printf("%d", answer);

	return 0;
}