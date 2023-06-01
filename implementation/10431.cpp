#include<iostream>

using namespace std;

int P, T, counts = 0;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	cin >> P;

	for (int i = 0; i < P; i++) {
		cin >> T;
		int arr[20] = { 0, };
		for (int j = 0; j < 20; j++)
			cin >> arr[j];
		for (int a = 1; a < 20; a++) {
			for (int b = 0; b < a; b++)
				if (arr[a] < arr[b])
					counts++;
		}

		cout << T << " " << counts << "\n";
		counts = 0;
	}

	return 0;
}