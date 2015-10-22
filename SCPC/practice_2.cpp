#include <cstdio>
#include <algorithm>

using namespace std;

int t, arr[300001];
int main() {
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", arr + i);

		sort(arr, arr + n);
		int maximum = 0;
		for (int i = 0; i < n; i++) maximum = max(maximum, arr[i] + n - i);
		int i = 0;
		for (; i < n; i++) {
			if (arr[i] + n >= maximum) break;
		}
		printf("Case #%d\n%d\n", c, n - i);
	}
}