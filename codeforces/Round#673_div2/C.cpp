#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	multimap<int, int> mm;
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		mm.emplace(x, i);
	}

	vector<int> ans(n + 1, n + 1);
	for (auto b{mm.begin()}; b != mm.end(); ) {
		auto e{mm.upper_bound(b -> first)};
		int k{max(b -> second + 1, n - prev(e) -> second)};
		for (auto it{b}; next(it) != e; ++it) {
			k = max(k, next(it) -> second - it -> second);
		}
		ans[k] = min(ans[k], b -> first);
		b = e;
	}

	int mn{ans[0]};
	for (int i{1}; i <= n; ++i) {
		mn = min(mn, ans[i]);
		if (mn == n + 1) cout << "-1 ";
		else cout << mn << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
