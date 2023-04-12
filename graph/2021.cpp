#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int N, L;
int s, e;
queue<int> q;
int dis[200001];
vector<int> subway[200001];
int BFS() {
	dis[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == e) {

			if (dis[e] - 1 > 0)
				return dis[e] - 1;
			return 0;
		}
		for (auto next : subway[now]) {
			if (dis[next] > -1) //이미 환승함  
				continue;
			if (next > 100000) //환승할 수 있는 역인 경우  
				dis[next] = dis[now] + 1;
			else // 그냥 일반 역인 경우  
				dis[next] = dis[now];
			q.push(next);
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &N, &L);

	memset(dis, -1, sizeof(dis));
	for (int i = 1; i <= L; i++) {
		int tmp;
		while (1) {
			scanf("%d", &tmp);

			if (tmp == -1)
				break;
			subway[tmp].push_back(i + 100000);
			subway[i + 100000].push_back(tmp);
		}
	}
	scanf("%d %d", &s, &e);


	printf("%d", BFS());

	return 0;
}