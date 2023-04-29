#include<stdio.h>
#define MAX_N 10000
using namespace std;

int N, M;
int arr[MAX_N + 1];

int main() {

	int answer = 0, left = 0, right = 0, tmp = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		left = i;
		right = i;
		tmp = arr[i];

		while (left <= right && right < N) {
			if (tmp == M)
				answer++;

			if (tmp + arr[++right] <= M) {
				tmp += arr[right];
			}
			else
				break;
		}
	}
	printf("%d ", answer);

	return 0;
}