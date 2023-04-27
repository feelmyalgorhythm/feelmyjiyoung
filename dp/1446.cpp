#include<iostream>
#include<vector>
#define MAX 987654321

using namespace std;

int N, D;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int main() {
	int s, e, len;
	init();

	cin >> N >> D;

	vector<int> dis(D + 1, MAX);
	vector<pair<int, int>> v[10000];

	for (int i = 0; i < N; i++) {
		cin >> s >> e >> len;

		v[e].push_back(make_pair(s, len));
	}

	dis[0] = 0;

	for (int i = 1; i <= D; i++) {
		//거리를 더하면서 작성하기
		if (v[i].size() == 0)
			dis[i] = dis[i - 1] + 1;
		else {
			for (pair<int, int> p : v[i]) {
				dis[i] = min(dis[i], min(dis[i - 1] + 1, dis[p.first] + p.second));
			}
		}
	}

	cout << dis[D];


	return 0;
}