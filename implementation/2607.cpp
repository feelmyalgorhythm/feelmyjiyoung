#include<iostream>

using namespace std;

string s, target;
int N, answer;
int tmp[26], m[26];

void initTmp() {
	for (int i = 0; i < 26; i++)
		tmp[i] = 0;
}

int main() {
	cin >> N;
	cin >> target;

	for (int i = 0; i < target.length(); i++)
		m[target[i] - 'A']++;

	for (int i = 1; i < N; i++) {
		cin >> s;

		initTmp();

		bool flag = true;
		int l = 0, r = 0;

		for (int j = 0; j < s.length(); j++) {
			tmp[s[j] - 'A']++;
		}


		for (int j = 0; j < 26; j++) {
			if (tmp[j] == m[j])
				continue;
			if (abs(tmp[j] - m[j]) > 1) {
				flag = false;
				break;
			}
			else if (tmp[j] < m[j])
				l++;
			else if (tmp[j] > m[j])
				r++;
			if (l > 1 || r > 1) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer++;
	}

	cout << answer;

	return 0;
}