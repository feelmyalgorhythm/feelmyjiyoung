#include<iostream>
#include<stack>

using namespace std;

int N;
stack<pair<int, int>> s;
stack<pair<int, int>> r;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	cin >> N;

	int answer[N] = { 0, }, tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		s.push(make_pair(i, tmp));
	}

	while (!s.empty()) {
		while (!r.empty() && s.top().second > r.top().second) {
			answer[r.top().first] = s.top().first + 1;
			r.pop();
		}
		r.push(s.top());
		s.pop();
	}

	while (!r.empty()) {
		answer[r.top().first] = 0;
		r.pop();
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";

	return 0;
}