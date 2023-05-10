#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int M;
int arr[21];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	string s;
	int n;

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> s;

		if (s == "add") {
			cin >> n;
			arr[n] = 1;
		}
		else if (s == "remove") {
			cin >> n;
			arr[n] = 0;
		}
		else if (s == "check") {
			cin >> n;
			if (arr[n])
				cout << "1 \n";
			else
				cout << "0 \n";
		}
		else if (s == "toggle") {
			cin >> n;
			if (arr[n])
				arr[n] = 0;
			else
				arr[n] = 1;
		}
		else if (s == "all") {
			memset(arr, 1, sizeof(arr));
		}
		else if (s == "empty") {
			memset(arr, 0, sizeof(arr));
		}
	}

	return 0;
}