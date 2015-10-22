#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[2000001], t, num, n, tmp, i, c = 1, maximum, last, m;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);

	for (; c <= t; c++) {
		m = 0;
		scanf("%d", &n);

		for (i = 0; i < n; i++) {
			scanf("%d", &num);
			cnt[num]++;
			m = max(m, num);
		}

		last = n - 1;
		num = maximum = 0;

		for (i = m; i >= 0; i--) {
			int &ct = cnt[i];

			if (ct) {
				num += ct;
				if (maximum <= num + i) {
					last = num;
					maximum = num + i;
				}

				ct = 0;
			}
		}

		printf("Case #%d\n%d\n", c, last);
	}
}