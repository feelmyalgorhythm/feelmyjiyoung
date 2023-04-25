#include<iostream>
#include<queue>
#define MAX 100000
#define INF 987654321

using namespace std;

int N, K;
int visited[MAX + 1];
queue<int> q;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int move() {
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) {
			return visited[now];
		}

		if (now - 1 >= 0 && visited[now - 1] > visited[now] + 1) {
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= MAX && visited[now + 1] > visited[now] + 1) {
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 <= MAX && visited[now * 2] > visited[now]) {
			visited[now * 2] = visited[now];
			q.push(now * 2);
		}
	}

}

int main() {

	init();

	cin >> N >> K;

	for (int i = 0; i <= MAX; i++) {
		visited[i] = INF;
	}

	visited[N] = 0;

	cout << move();

	return 0;
}