#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct PLL {
	int first, second;

	PLL(int a, int b) :first(a), second(b) {};

	inline bool operator<(const PLL &l) const {
		if (first == l.first) return second>l.second;
		else return first < l.first;
	};
};

int main() {
	int t, a, b;
	scanf("%d", &t);
	vector<PLL> ranges;
	vector<int> arr;

	for (int c = 1; c <= t; c++) {
		ranges.clear();
		arr.clear();

		int n;
		scanf("%d", &n);

		for (size_t i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);

			ranges.push_back(PLL(a, b));
		}
		sort(ranges.begin(), ranges.end());

		for (int i = n - 1; i >= 0; i--) {
			int &t = ranges[i].second;

			vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), t);
			if (iter == arr.end()) arr.push_back(t);
			else if (*iter == t && iter + 1 == arr.end()) arr.push_back(t);
			else *iter = t;
		}

		printf("Case #%d\n%d\n", c, arr.size());
	}
}