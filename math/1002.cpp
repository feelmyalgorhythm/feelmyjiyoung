#include<stdio.h>

using namespace std;

int T;
int x1, y1, r1, x2, y2, r2;

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int max = (r1 + r2) * (r1 + r2);
		int min = (r1 - r2) * (r1 - r2);


		if (d == 0) {
			if (min == 0)
				printf("-1 \n");
			else
				printf("0 \n");
		}
		else {
			if (d == max || d == min)
				printf("1 \n");
			else if (max > d && d > min)
				printf("2 \n");
			else
				printf("0 \n");
		}
	}

	return 0;
}