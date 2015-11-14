#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

short dist[500][500];
vector<short> path[500][500];
const short INF = numeric_limits<short>::max();

bool check[500];

bool checking(int start, int end) {
	if (start == end) return true;

	vector<short> &make = path[start][end];

	if (make.size() == 1) {
		if (checking(start, make[0])) {
			check[make[0]] = true;
		}

		return true;
	}
	else return false;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		int n, m;
		scanf("%d%d", &n, &m);

		fill_n(check, n, false);
		for (int i = 0; i < n; i++) {
			fill_n(dist[i], n, INF);
			dist[i][i] = 0;
			for (int j = 0; j < n; j++) path[i][j].clear();
		}

		for (int i = 0; i < m; i++) {
			short u, v, d;
			scanf("%hd%hd%hd", &u, &v, &d);
			u--, v--;
			dist[u][v] = dist[v][u] = d;
			path[u][v].push_back(u);
			path[v][u].push_back(v);
		}


		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (dist[i][j] == dist[i][k] + dist[k][j] && k != j && k != i) {
						path[i][j].push_back(k);
					}
					else if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];

						path[i][j].clear();
						path[i][j].push_back(k);
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				checking(i, j);
			}
		}

		vector<int> re;
		for (int i = 0; i < n; i++) if (check[i]) re.push_back(i);;

		printf("%d ", re.size());
		for (int i = 0; i < re.size(); i++) printf("%d ", re[i]);
	}
}