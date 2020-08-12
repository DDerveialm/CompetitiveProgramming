#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool check(int n, int x, priority_queue<pair<int, int>> pq) {
	vector<int> bag(n), rmd(n);
	for (int i = 0; i < n; ++i) {
		if (pq.empty()) return false;
		bag[i] = pq.top().second;
		rmd[i] = pq.top().first - 1;
		pq.pop();
		if (i - x >= 0 && rmd[i - x])
			pq.emplace(rmd[i - x], bag[i - x]);
	}
	return true;
}

int method1() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			int f;
			cin >> f;
			++vec[f];
		}
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; ++i)
			if (vec[i]) pq.emplace(vec[i], i);

		int l = 0, r = n - 2; // [l:r]
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (check(n, m, pq) == true) l = m;
			else r = m - 1;
		}
		cout << l << endl;
	}
	return 0;
}

int method2() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			int f;
			cin >> f;
			++vec[f];
		}
		int max = 0, maxfreq;
		for (const auto& a : vec) {
			if (a > max) {
				max = a;
				maxfreq = 1;
			} else if (a == max) ++maxfreq;
		}
		cout << ((n - maxfreq) / (max - 1)) - 1 << endl;
	}
}

int main() {
//	return method1();
	return method2();
}
