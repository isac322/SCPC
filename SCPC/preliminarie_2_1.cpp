#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

inline long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	long long c;

	while (b > 0) {
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}

int main() {
	int t, cnt;
	long long num, prev;
	scanf("%d", &t);
	set<long long> diff;

	for (int c = 1; c <= t; c++) {
		diff.clear();
		cnt = 0;

		int n;
		scanf("%d%lld", &n, &prev);

		for (int i = 1; i < n; i++) {
			scanf("%lld", &num);

			diff.insert(num - prev);
			prev = num;
		}

		long long cd;
		size_t size = diff.size();
		if (size > 1) {
			set<long long>::iterator iter = diff.begin();
			if (*iter == 0) {
				printf("Case #%d\n0\n", c);
				continue;
			}
			cd = gcd(*iter++, *iter++);

			for (size_t i = 2; i < size; i++) {
				cd = gcd(cd, *iter++);
			}
		}
		else cd = *diff.begin();

		if (cd < 2) cnt = 1;
		else {
			int tmp = sqrtl(cd);

			for (int i = 1; i <= tmp; i++) {
				if (cd%i == 0) cnt += 2;
			}

			if ((long long) tmp * tmp == cd) cnt++;
		}

		printf("Case #%d\n%d\n", c, cnt);
	}

	return 0;
}