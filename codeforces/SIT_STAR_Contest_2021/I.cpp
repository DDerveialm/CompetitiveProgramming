#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (auto& [a, b] : v) cin >> a >> b, --a, --b;

	int ans;
	{
		vector<int> f(2 * n);
		for (int i{0}; i < n; ++i) {
			auto& [a, b]{v[i]};
			++f[a];
			if (b != a) ++f[b];
		}

		int mx{-1}, mx2{-1};
		for (int i{0}; i < 2 * n; ++i)
			if (f[i] > mx) mx2 = mx, mx = f[i];
			else if (f[i] > mx2) mx2 = f[i];
		ans = 2 * n - mx - mx2;
	}
	{
		vector<int> f(2 * n);
		for (int i{0}; i < n; ++i) {
			auto& [a, b]{v[i]};
			++f[a], ++f[b];
		}

		int mx{-1};
		for (int i{0}; i < 2 * n; ++i)
			if (f[i] >= mx) mx = f[i];
		ans = min(ans, 2 * n - mx);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
