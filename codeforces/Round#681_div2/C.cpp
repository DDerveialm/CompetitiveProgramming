#include <iostream>
#include <vector>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& x : v) cin >> x.fi;
	for (auto& x : v) cin >> x.se;

	int l{1}, r{static_cast<int>(1e9) + 1}; // [l:r)
	while (r - l > 1) {
		int m{(l + r) / 2};
		long long sum{0};
		for (auto& x : v) if (x.fi > m - 1) sum += x.se;
		if (sum > m - 1) l = m;
		else r = m;
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
