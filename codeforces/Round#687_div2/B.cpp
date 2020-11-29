#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{n};
	for (int c{1}; c <= 100; ++c) {
		int cnt{0};
		for (int i{0}; i < n; i += k) {
			while (i < n && v[i] == c) ++i; // find next
			if (i < n) ++cnt;
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
