#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> arr;
map<int, int> m;
int N, K;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int tmp, answer = 0, start = 0;

	init();

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		m[tmp]++;

		while (m[tmp] > K) {
			m[arr[start++]]--;
		}
		answer = max(answer, i - start + 1);
	}

	cout << answer;

	return 0;
}