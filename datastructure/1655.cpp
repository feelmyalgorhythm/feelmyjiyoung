#include<stdio.h>
#include<queue>

using namespace std;

priority_queue<int> pq1; // 3 2 1
priority_queue<int, vector<int>, greater<int>> pq2; // 4 5 6

int main() {
	int N, v, tmp;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &v);

		if (pq1.size() > 0 && pq1.top() > v)
			pq1.push(v);
		else
			pq2.push(v);

		while (1) { // 순서 정렬  
			if (i % 2 == 0 && pq1.size() == pq2.size())
				break;
			if (i % 2 == 1 && pq2.size() == pq1.size() + 1)
				break;
			if (pq2.size() > pq1.size()) {
				tmp = pq2.top();
				pq2.pop();
				pq1.push(tmp);
			}
			else {
				tmp = pq1.top();
				pq1.pop();
				pq2.push(tmp);
			}
		}
		if (i % 2 == 0)
			printf("%d \n", pq1.top());
		else
			printf("%d \n", pq2.top());
	}
	return 0;
}