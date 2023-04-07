#include<iostream>
#include<map>
#include<vector>
#define MAX 200000
using namespace std;

int T, F;
string f1, f2;
int parent[MAX + 1];
int result[MAX + 1];

int Find(int x) {
	if (x == parent[x])
		return x;
	return Find(parent[x]);
}

void Union(int x, int y) {
	int p1 = Find(x);
	int p2 = Find(y);

	if (p1 != p2) {
		result[p1] += result[p2];
		result[p2] = 1;
		parent[p2] = p1;
	}

	cout << result[p1] << '\n';
}

void init() {
	for (int i = 1; i < MAX + 1; i++) {
		result[i] = 1;
		parent[i] = i;
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int count = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> F;

		init();
		count = 1;
		map<string, int> list;

		for (int j = 0; j < F; j++) {

			cin >> f1 >> f2;

			if (list[f1] == 0)
				list[f1] = count++;
			if (list[f2] == 0)
				list[f2] = count++;
			Union(list[f1], list[f2]);
		}
	}

	return 0;
}