#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int cnt{0}, need_max{0}, need_min{0};
	for (int i{0}, x{1}; i < n && x <= 2 * n; ++x) {
		if (x == v[i]) {
			++i;
			if (cnt) --cnt;
			else ++need_max;
		} else ++cnt;
	}
	cnt = 0;
	for (int i{n - 1}, x{2 * n}; i >= 0 && x >= 1; --x) {
		if (x == v[i]) {
			--i;
			if (cnt) --cnt;
			else ++need_min;
		} else ++cnt;
	}

	cout << n + 1 - need_max - need_min << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
