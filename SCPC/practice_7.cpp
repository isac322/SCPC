#include <cstdio>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

int n, arr[5000];
unordered_map<int, int> map;

int main() {
	setbuf(stdout, NULL);
	int t, cnt;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		map.clear();
		cnt = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int &num = arr[i];
			scanf("%d", &num);

			for (int j = 0; j <= i; j++) map[num + arr[j]] = true;

			for (int j = 0; j < i; j++) {
				if (map.find(num - arr[j]) != map.end()) {
					cnt++;
					break;
				}
			}
		}

		printf("Case #%d\n%d\n", c, cnt);
	}
}