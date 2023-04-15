#include<iostream>
#include<vector>
#include<string>

using namespace std;

int K;
string gear[5];
vector<pair<int, int>> oper;

int calculateMove() { // 12시 방향 기어로 점수 확인하기  
	int sum = 0, mul = 1;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') {
			sum += mul * 1;
		}
		mul *= 2;
	}
	return sum;
}

void moveToRight(int n) {
	string tmp = gear[n].substr(0, 7);
	gear[n] = gear[n][7] + tmp;
}
void moveToLeft(int n) {
	string tmp = gear[n].substr(1);
	gear[n] = tmp + gear[n][0];
}

void makeMove(int gearNumber, int direction) {
	//나보다 큰 놈, 나보다 작은 놈 두 경우로 생각해서 풀기  
	int rotate[5] = { 0, };
	int dir = direction;
	int now = gearNumber;

	rotate[gearNumber] = direction;


	for (int i = gearNumber + 1; i <= 3; i++) { //오른쪽과 비교  
		if (gear[now][2] == gear[i][6]) {
			rotate[i] = 0;
			break;
		}
		else {
			rotate[i] = -dir;
			dir = -dir;
			now++;
		}
	}

	dir = direction;
	now = gearNumber;

	for (int i = gearNumber - 1; i >= 0; i--) { //왼쪽과 비교  
		if (gear[i][2] == gear[now][6]) {
			rotate[i] = 0;
			break;
		}
		else {
			rotate[i] = -dir;
			dir = -dir;
			now--;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (rotate[i] == 0)
			continue;
		if (rotate[i] == 1) {
			moveToRight(i);
		}
		else if (rotate[i] == -1)
			moveToLeft(i);
	}

	return;

}

int main() {

	int tmp, answer = 0;

	for (int i = 0; i < 4; i++)
		cin >> gear[i];

	cin >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		makeMove(a - 1, b);

	}
	answer = calculateMove();
	cout << answer;

	return 0;
}