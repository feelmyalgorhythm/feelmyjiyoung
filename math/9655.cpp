#include<iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	int N;

	cin >> N;

	if (N % 2 == 0)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}