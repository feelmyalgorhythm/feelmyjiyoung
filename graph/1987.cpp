#include<stdio.h>
#define MAX_R 20

using namespace std;

char board[MAX_R + 1][MAX_R + 1];
bool visited[36];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int R, C, answer = 0;

void moveNext(int x, int y, int counts) {
	if (counts > answer)
		answer = counts;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;

		if (!visited[board[nx][ny] - 'A' + 1]) {
			visited[board[nx][ny] - 'A' + 1] = true;
			moveNext(nx, ny, counts + 1);
			visited[board[nx][ny] - 'A' + 1] = false;
		}
	}
}

int main() {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
		scanf("%s", board[i]);

	visited[board[0][0] - 'A' + 1] = true;

	moveNext(0, 0, 1);

	printf("%d", answer);

	return 0;
}