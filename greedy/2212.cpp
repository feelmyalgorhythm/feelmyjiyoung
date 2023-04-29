#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> sensor;
vector<int> dis;

int main() {
	int tmp = 0, answer = 0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		sensor.push_back(tmp);
	}

	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < sensor.size() - 1; i++)
		dis.push_back(sensor[i + 1] - sensor[i]);

	sort(dis.begin(), dis.end());

	for (int i = 0; i < N - K; i++) {
		answer += dis[i];
	}

	printf("%d", answer);

	return 0;
}