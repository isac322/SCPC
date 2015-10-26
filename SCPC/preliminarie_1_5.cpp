#include <cstdio>
#include <limits>
#include <vector>

using namespace std;

const int MAX_DISTANCE = numeric_limits<int>::max();
int cost[1000][1000];

int dist[1000];
bool visited[1000];
bool passed[1000];
vector<int> prevs[1000];

int vertex, edge;


void getPassedUniv(int src, int dest, vector<int>& path) {
	if (path.size() > vertex) return;

	if (src == dest) {
		for (vector<int>::iterator iter = path.begin() + 1; iter != path.end(); ++iter) {
			passed[*iter] = true;
		}
		return;
	}

	for (vector<int>::iterator it = prevs[dest].begin(); it != prevs[dest].end(); it++) {
		size_t size = path.size();

		path.push_back(dest);
		getPassedUniv(src, *it, path);

		path.resize(size);
	}
}


void shortPath(int src, int dest) {
	fill_n(visited, vertex, false);

	fill_n(dist, vertex, MAX_DISTANCE);
	for (int i = 0; i < vertex; i++) prevs[i].clear();

	dist[src] = 0;

	int cur = src;
	visited[cur] = true;

	while (visited[dest] == false) {
		int min = MAX_DISTANCE;
		int m = -1;

		for (int i = 0; i < vertex; i++) {
			int d;
			if (cost[cur][i] == MAX_DISTANCE) {
				d = MAX_DISTANCE;
			}
			else {
				d = dist[cur] + cost[cur][i];
			}

			if (visited[i] == false) {
				if (d < dist[i]) {
					dist[i] = d;
					prevs[i].clear();
					prevs[i].push_back(cur);
				}
				else if (d == dist[i]) {
					prevs[i].push_back(cur);
				}

				if (min > dist[i]) {
					min = dist[i];
					m = i;
				}
			}
		}

		if (min == MAX_DISTANCE) break;

		cur = m;
		visited[cur] = true;
	}

	if (visited[dest]) {
		vector<int> path;
		getPassedUniv(src, dest, path);
	}
}


int main() {
	setbuf(stdout, NULL);
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		scanf("%d %d", &vertex, &edge);

		fill_n(passed, vertex, false);
		for (int i = 0; i < vertex; i++) {
			fill_n(cost[i], vertex, MAX_DISTANCE);
			cost[i][i] = 0;
		}

		for (int i = 0; i < edge; i++) {
			short u, v;
			scanf("%hd %hd", &u, &v);
			u--, v--;
			scanf("%d", cost[u] + v);
			cost[v][u] = cost[u][v];
		}

		for (int i = 0; i < vertex; i++) {
			for (int j = i + 1; j < vertex; j++) {
				if (i == j) continue;

				shortPath(i, j);
			}
		}

		printf("Case #%d\n", c);
		int cnt = 0;
		for (int i = 0; i < vertex; i++) if (!passed[i]) cnt++;
		printf("%d ", cnt);
		for (int i = 0; i < vertex; i++) {
			if (!passed[i]) printf("%d ", i + 1);
		}
		puts("");
	}
}