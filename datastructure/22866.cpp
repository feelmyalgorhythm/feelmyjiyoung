#include<iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> lefts, rights;

int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	int tmp;

	init();

	cin >> N;
	vector<int> buildings(N);
	vector<pair<int, int>> dis(N); // 개수, 가장 작은 수  

	for (int i = 0; i < N; i++) {
		cin >> buildings[i];
	}


	for (int i = N - 1; i >= 0; i--) {
		while (!rights.empty() && buildings[i] >= buildings[rights.top()]) {
			rights.pop();
		}
		if (!rights.empty()) {
			dis[i].first += rights.size();
			dis[i].second = rights.top();
		}
		rights.push(i);
	}

	for (int i = 0; i < N; i++) {
		while (!lefts.empty() && buildings[i] >= buildings[lefts.top()]) {
			lefts.pop();
		}
		if (!lefts.empty()) {
			dis[i].first += lefts.size();
			if (abs(dis[i].second - i) >= abs(lefts.top() - i))
				dis[i].second = lefts.top();
		}
		lefts.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (dis[i].first == 0)
			cout << "0 \n";
		else
			cout << dis[i].first << " " << dis[i].second + 1 << "\n";
	}

	return 0;
}