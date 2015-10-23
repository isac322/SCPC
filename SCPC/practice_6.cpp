#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	char next;
	bool up;
	scanf("%d\n", &t);

	for (int tc = 1; tc <= t; tc++) {
		int n, k, r, c;
		unsigned long long sum = 1, num = 1;
		scanf("%d %d\n", &n, &k);

		r = 0, c = --n;
		for (int i = 0; i < k; i++) {
			next = getchar();

			up = ((r + (n - c)) & 1) == 0;

			if (r == c) {
				if (up) {
					switch (next) {
						case 'U':
							num -= ((n - r) << 1) + 1;
							break;
						case 'L':
							num -= (n - r) << 1;
							break;
						case 'D':
							num += (r << 1) + 1;
							break;
						case 'R':
							num += r << 1;
					}
				}
				else {
					switch (next) {
						case 'L':
							num -= (r << 1) + 1;
							break;
						case 'U':
							num -= (r << 1);
							break;
						case 'R':
							num += ((n - r) << 1) + 1;
							break;
						case 'D':
							num += ((n - r) << 1);
					}

				}
			}
			else if (r < c) {
				if (up) {
					switch (next) {
						case 'U':
							num -= ((n - c) << 1) + 1;
							break;
						case 'L':
							num -= (n - c) << 1;
							break;
						case 'D':
							num += (r << 1) + 2;
							break;
						case 'R':
							num += (r << 1) + 1;
					}
				}
				else {
					switch (next) {
						case 'U':
							num -= (r << 1);
							break;
						case 'L':
							num -= (r << 1) + 1;
							break;
						case 'D':
							num += ((n - c) << 1) + 1;
							break;
						case 'R':
							num += ((n - c) << 1) + 2;
					}

				}
			}
			else {
				if (up) {
					switch (next) {
						case 'U':
							num -= ((n - r) << 1) + 2;
							break;
						case 'L':
							num -= ((n - r) << 1) + 1;
							break;
						case 'D':
							num += (c << 1) + 1;
							break;
						case 'R':
							num += c << 1;
					}
				}
				else {
					switch (next) {
						case 'U':
							num -= (c << 1) + 1;
							break;
						case 'L':
							num -= (c << 1) + 2;
							break;
						case 'D':
							num += ((n - r) << 1);
							break;
						case 'R':
							num += ((n - r) << 1) + 1;
					}

				}
			}

			switch (next) {
				case 'U': r--; break;
				case 'D': r++; break;
				case 'L': c++; break;
				case 'R': c--; break;
			}
			sum += num;
		}
		getchar();

		printf("Case #%d\n%llu\n", tc, sum);
	}
}