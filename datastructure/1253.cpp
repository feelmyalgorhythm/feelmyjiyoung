#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> arr;
long long N;

int main() {
	long long tmp;
	int left, right, answer = 0;

	scanf("%lld", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &tmp);

		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		left = 0;
		right = arr.size() - 1;

		while (left < right) {
			int sum = arr[left] + arr[right];
			if (sum == arr[i]) {
				if (left != i && right != i) {
					answer++;
					break;
				}
				else if (left == i)
					left++;
				else if (right == i)
					right--;
			}
			else if (sum < arr[i])
				left++;
			else
				right--;
		}
	}
	printf("%d", answer);

	return 0;
}