#include <cstdio>
#include <algorithm>
#include <cmath>

#define INF 987654321
#define NVISITED -1

using namespace std;

int m, n, k;
int map[101][101];
bool check[101][101];

int dp[11][101][101];

int solve(int r, int c, int b) {
	if (r < 0 || c < 0 || b < 0) return INF;
	else if (r == 0 && c == 0 && b == 0) return 0;

	int &p = dp[b][r][c];
	if (p != NVISITED) return p;
	else p = INF;

	int &here = map[r][c];

	if (check[r][c]) b--;

	int ret = solve(r - 1, c, b);
	p = min(p, ret + abs(here - map[r - 1][c]));

	ret = solve(r, c - 1, b);
	p = min(p, ret + abs(here - map[r][c - 1]));

	return p;
}

int main() {
	setbuf(stdout, NULL);
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 11; j++) fill_n(dp[j][i], 101, NVISITED);
			fill_n(check[i], 101, false);
		}
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				scanf("%d", map[i] + j);

				if (map[i][j] < 0) {
					check[i][j] = true;
					map[i][j] = -map[i][j];
				}
			}
		}

		int ret = solve(n, m, k);
		for (int i = k + 1; i < 11; i++) {
			ret = min(ret, solve(n, m, i));
		}

		printf("Case #%d\n%d\n", c, ret);
	}

	return 0;
}