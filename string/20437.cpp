#include<iostream>
#define INF 987654321

using namespace std;

int T, K;
string W;
int alpha[26];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void set() {
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;
}

int main() {

	init();

	cin >> T;

	for (int i = 0; i < T; i++) {
		int min = INF, max = 0, counts = 0;

		cin >> W >> K;

		for (int j = 0; j < W.length(); j++)
			alpha[W[j] - 'a']++;

		for (int j = 0; j < W.length(); j++) {
			if (alpha[W[j] - 'a'] < K)
				continue;
			counts = 0;
			for (int a = j; a < W.length(); a++) {
				if (W[a] == W[j])
					counts++;

				if (counts == K) {
					min = a - j + 1 > min ? min : a - j + 1;
					max = a - j + 1 < max ? max : a - j + 1;
					break;
				}
			}
		}
		if (max == 0 && min == INF)
			cout << "-1 \n"; a
		else
			cout << min << " " << max << "\n";

		set();
	}

	return 0;
}