#include <cstdio>

using namespace std;

int main() {
	int t, n;
	unsigned tmp;
	scanf("%d", &t);

	for (int j = 1; j <= t; j++) {
		scanf("%d", &n);
		unsigned re = 0;
		for (int i = 0; i < n; i++) {
			scanf("%u", &tmp);
			re ^= tmp;
		}
		printf("Case #%d\n%d\n", j, re);
	}

	return 0;
}