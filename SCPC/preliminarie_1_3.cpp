#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		int n, tmp, a, first;
		bool check = true;
		scanf("%d", &n);

		int i = 2;
		for (;; i++) {
			tmp = n;

			first = tmp%i;
			tmp /= i;

			check = true;

			while (tmp) {
				a = tmp%i;
				tmp /= i;

				if (a != first) {
					check = false;
					break;
				}
			}

			if (check) break;
		}

		printf("Case #%d\n%d\n", c, i);
	}
}