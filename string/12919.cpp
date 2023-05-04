#include<iostream>
#include<algorithm>
using namespace std;

string s, t;
bool flag = false;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void makeS(string now) {

	if (now.length() == s.length()) {
		if (now == s)
			flag = true;
		return;
	}
	int lastIndex = now.length() - 1;

	if (now[lastIndex] == 'A') {
		string tmp = now.substr(0, lastIndex);
		makeS(tmp);
	}
	if (now[0] == 'B') {
		string tmp = now.substr(1, now.length());
		reverse(tmp.begin(), tmp.end());
		makeS(tmp);
	}
}

int main() {
	init();

	cin >> s >> t;

	makeS(t);

	cout << flag;
	return 0;
}