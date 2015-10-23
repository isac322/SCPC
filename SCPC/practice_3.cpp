#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	priority_queue<int, vector<int>, greater<int> > que;
	for (int c = 1; c <= t; c++) {
		int n, k, q;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &q);
			que.push(q);
		}

		for (int i = 0; i < n - k; i++) {
			scanf("%d", &q);
			if (q > que.top()) {
				que.pop();
				que.push(q);
			}
		}

		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += que.top();
			que.pop();
		}
		printf("Case #%d\n%d\n", c, sum);
	}
}