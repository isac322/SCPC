#include <cstdio>
#include <algorithm>

using namespace std;

int rock[1000001];
int n, k;

int solve() {
	int cnt = 0, far;
	for (int index = 0; index < n; cnt++) {
		const int &r = rock[index];

		if (rock[index + 1] - r > k) return -1;
		for (far = index + 1; far <= n && rock[far] - r <= k; far++);
		index = far - 1;
	}

	return cnt;
}

int main() {
	setbuf(stdout, NULL);
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", rock + i);
		scanf("%d", &k);

		printf("Case #%d\n%d\n", c, solve());
	}
}