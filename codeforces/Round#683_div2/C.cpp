#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	long long w;
	cin >> n >> w;
	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i].fi, v[i].se = i + 1;

	sort(v.rbegin(), v.rend());
	long long cnt{0};
	vector<int> ans{};
	for (auto& x : v) {
		if (cnt >= (w + 1) / 2) break;
		if (cnt + x.fi <= w) {
			cnt += x.fi;
			ans.push_back(x.se);
		}
	}

	if (cnt >= (w + 1) / 2) {
		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	} else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
