#include<stdio.h>
#include<queue>
#define MAX 1000000

using namespace std;

int F, S, G, U, D; // 총 F층인 건물에서 S->G층으로, U-> 그만큼 위로, D -> 그만큼 아래로  
queue<pair<int, int>> floors;
bool visited[MAX + 1];

void useEle() {
	while (!floors.empty()) {
		pair<int, int> now = floors.front();

		if (now.first == G) {
			printf("%d", now.second);
			return;
		}
		if (now.first + U <= F)
			if (!visited[now.first + U]) {
				floors.push(make_pair(now.first + U, now.second + 1));
				visited[now.first + U] = true;
			}
		if (now.first - D >= 1)
			if (!visited[now.first - D]) {
				floors.push(make_pair(now.first - D, now.second + 1));
				visited[now.first - D] = true;
			}

		floors.pop();
	}
	printf("use the stairs");
}

int main() {

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	floors.push(make_pair(S, 0));
	visited[S] = true;

	useEle();

	return 0;
}