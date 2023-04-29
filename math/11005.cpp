#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

long long N;
int B;

//1-9
// 10 - 35 => A -> Z

int main() {

	scanf("%lld %d", &N, &B);
	string answer = "";

	while (N >= B) {
		int res = N % B;


		if (res >= 10)
			answer += (res + 'A' - 10);
		else
			answer += (res + '0');

		N /= B;
	}

	if (N >= 10)
		answer += (N + 'A' - 10);
	else
		answer += (N + '0');

	reverse(answer.begin(), answer.end());

	printf("%s", answer.c_str());

	return 0;
}