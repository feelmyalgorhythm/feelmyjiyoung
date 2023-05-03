#include<iostream>
#include<queue>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	int N, tmp;

	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			pq.push(tmp);

			if (pq.size() > N)
				pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}