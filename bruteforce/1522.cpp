#include<iostream>

using namespace std;

string s;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	cin >> s;
	int aCount = 0, answer = s.length();

	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'a')
			aCount++;

	for (int i = 0; i < s.length(); i++) {
		int count = aCount;
		int tmp = 0; 

		for (int j = i; j < i + s.length(); j++) {
			if (count == 0)
				break;
			if (s[j % s.length()] == 'b') {
				tmp++;

			}
			count--;
		}
		answer = min(answer, tmp);
	}

	cout << answer;

	return 0;
}