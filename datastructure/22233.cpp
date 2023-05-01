#include<iostream>
#include<map>

using namespace std;

int N, M;
string s;
map<string, int> keyword;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s;
		keyword[s]++;
	}

	for (int i = 0; i < M; i++) {
		int answer = 0;
		cin >> s;
		string tmp = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ',') {
				keyword.erase(tmp);
				tmp = "";
				continue;
			}
			tmp += s[j];
		}
		keyword.erase(tmp);

		cout << keyword.size() << "\n";
	}

	return 0;
}