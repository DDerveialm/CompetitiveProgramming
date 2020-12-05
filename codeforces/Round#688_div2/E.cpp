#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> adj{};
int ans;

int dfs(int u, int w = -1) {
	int mx{0}, mx2{0}, mn{numeric_limits<int>::max()};
	for (auto& v : adj[u]) {
		if (v != w) {
			auto r{dfs(v, u)};
			if (r >= mx) mx2 = mx, mx = r;
			else if (r > mx2) mx2 = r;
			mn = min(mn, r);
		}
	}

	if (u == 0) ans = max(ans, mx2 + 1);
	else ans = max(ans, mx + 1);
	if (mn == numeric_limits<int>::max()) return 1;
	else return mn + 1;
}

void solve() {
	int n;
	cin >> n;
	adj.assign(n, {});

	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = 0;
	dfs(0, -1);

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
