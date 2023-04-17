#include<stdio.h>
#include<vector>
#include<deque>
#include<map>

using namespace std;

int N, K, L; //������ ũ��, ����� ����, ���� ���� ��ȯ Ƚ��  
int board[100][100];
map<int, char> directions;
deque<pair<int, int>> bam;


int moveBam() {
	int dir = 1, sec = 0;
	while (1) {

		int x = bam.front().first;
		int y = bam.front().second;

		if (dir == 1)	// �� 
			bam.push_front(make_pair(x, y + 1));
		else if (dir == 2) // �Ʒ�  
			bam.push_front(make_pair(x - 1, y));
		else if (dir == 3) // �� 
			bam.push_front(make_pair(x, y - 1));
		else //dir==4 ��   
			bam.push_front(make_pair(x + 1, y));

		sec++;

		if (board[bam.front().first][bam.front().second] == 2) //���� �ٽ� ���� ���  
			break;
		if (bam.front().first == 0 || bam.front().first == N + 1 || bam.front().second == 0 || bam.front().second == N + 1) //���� ���� ���  
			break;

		if (board[bam.front().first][bam.front().second] == 0) { //����� ���� ���  
			board[bam.back().first][bam.back().second] = 0;
			bam.pop_back();
		}

		board[bam.front().first][bam.front().second] = 2;

		if (directions[sec] == 'L') { //�� 
			dir++;
			if (dir == 5)
				dir = 1;

		}
		if (directions[sec] == 'D') { // �� 
			dir--;
			if (dir == 0)
				dir = 4;
		}
	}
	return sec;
}

int main() {
	int tmp1, tmp2;
	char dir;

	scanf("%d", &N);

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		board[tmp1][tmp2] = 1;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		scanf("%d %c", &tmp1, &dir);
		directions[tmp1] = dir;
	}

	bam.push_back(make_pair(1, 1)); // ó�� ����  

	printf("%d", moveBam());

	return 0;
}