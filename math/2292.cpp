#include<iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	int N, answer = 0;

	cin >> N;

	for (int sum = 2; sum <= N; answer++) {
		sum += 6 * answer;
	}

	if (N == 1)
		answer = 1;

	cout << answer;

	return 0;
}