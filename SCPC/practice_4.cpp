#include <cstdio>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
	int t, a, b, c, d, e, n, x, y, distance;
	const int num[] = { 6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10 };
	double angle;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &n);

		int sum = 0;
		a *= a, b *= b, c *= c, d *= d, e *= e;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);

			distance = x*x + y*y;

			angle = atan2(y, x) * 180 / M_PI + 9;
			if (angle < 0) angle = 360 + angle;

			int base = num[int(angle / 18)];

			if (distance > e) sum += 0;
			else if (distance < a) sum += 50;
			else if (distance > b && distance < c) sum += base * 3;
			else if (distance > d && distance < e) sum += base * 2;
			else sum += base;
		}

		printf("Case #%d\n%d\n", tc, sum);
	}
}