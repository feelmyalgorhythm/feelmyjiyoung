#include<iostream>
#include<queue>
using namespace std;

int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[1000][1000];
int dis[1000][1000];
queue<pair<int, int>> q;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void printDis() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << dis[i][j] << " ";
		cout << "\n";
	}
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> p = q.front();

		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] <= 0)
				continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = -1;
				dis[nx][ny] = dis[p.first][p.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		q.pop();
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && dis[i][j] == 0)
				dis[i][j] = -1;
		}
}

int main() {
	init();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	bfs();
	printDis();
	return 0;
}