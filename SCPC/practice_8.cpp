#include <cstdio>
#include <algorithm>

using namespace std;

int h[100000], t, n, turn, len, cnt;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		turn = 0;
		scanf("%d", &n);
		len = n;

		for (int i = 0; i < n; i++) scanf("%d", h + i);

		while (len) {
			cnt = 0;

			for (int i = 1; i < len - 1; i++) {
				int m = min(h[i - 1], min(h[i], h[i + 1]));

				if (m == h[i]) m--;

				if (m != 0) h[cnt++] = m;
			}
			len = cnt;
			turn++;
		}

		printf("Case #%d\n%d\n", c, turn);
	}
}