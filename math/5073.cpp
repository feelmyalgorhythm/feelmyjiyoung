#include<iostream>

using namespace std;

int A, B, C;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main() {

	init();

	while (1) {
		cin >> A >> B >> C;

		if (A == 0 && B == 0 && C == 0)
			break;
		if (A == B && B == C)
			cout << "Equilateral \n";
		else if (A >= B + C || B >= A + C | C >= A + B)
			cout << "Invalid \n";
		else if (A == B || B == C || A == C)
			cout << "Isosceles \n";
		else if (A != B && B != C && C != A)
			cout << "Scalene \n";
	}
	return 0;
}