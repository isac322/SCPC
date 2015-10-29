#include <cstdio>
#include <algorithm>

using namespace std;

int n, arr[5000];
#define half 200000
bool map[(half << 1) + 1];

int main() {
	setbuf(stdout, NULL);
	int t, cnt;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		fill_n(map, (half << 1) + 1, false);
		cnt = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int &num = arr[i];
			scanf("%d", &num);

			for (int j = 0; j <= i; j++) map[num + arr[j] + half] = true;

			for (int j = 0; j < i; j++) {
				if (map[num - arr[j] + half]) {
					cnt++;
					break;
				}
			}
		}

		printf("Case #%d\n%d\n", c, cnt);
	}
}