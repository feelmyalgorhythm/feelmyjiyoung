#include<iostream>
#include<cmath>

using namespace std;

int H, W, N, M;
int a, b;
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	init();

	cin >> H >> W >> N >> M;

	if (H % (N + 1) == 0) {
		a = H / (N + 1);
	}
	else {
		a = H / (N + 1) + 1;
	}

	if (W % (M + 1) == 0) {
		b = W / (M + 1);
	}
	else {
		b = W / (M + 1) + 1;
	}

	cout << a * b;

	return 0;
}