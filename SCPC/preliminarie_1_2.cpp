#include <cstdio>
#include <algorithm>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;

char room[1000][1001];
bool check[1000][1000];
int dx[3][4] = {
	{1,-1,0,0},
	{0,0,-1,1},
	{0,0,1,-1}
};
int dy[3][4] = {
	{0,0,1,-1},
	{-1,1,0,0},
	{1,-1,0,0}
};
int next_dir[3][4] = {
	{LEFT,RIGHT,UP,DOWN},
	{DOWN,UP,RIGHT,LEFT},
	{UP,DOWN,LEFT,RIGHT}
};

int main() {
	int t;
	scanf("%d\n", &t);

	for (int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++) {
			fill_n(check[i], n, false);
			scanf("%s", room[i]);
		}

		int r = 0, c = 0;
		int direction = LEFT;

		while (!(r < 0 || r >= n || c < 0 || c >= n)) {
			char type = room[r][c] - '0';
			if (type) check[r][c] = true;

			r = r + dy[type][direction];
			c = c + dx[type][direction];
			direction = next_dir[type][direction];
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (check[i][j]) cnt++;

		printf("Case #%d\n%d\n", tc, cnt);
	}
}