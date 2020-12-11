#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int n, a, b, da, db;
int h, dist, diam;

int dfs(int u, int w = -1) {
	int mx{0};
	if (u == b) dist = h;
	for (auto& v : adj[u])
		if (v != w) {
			++h;
			auto len{1 + dfs(v, u)};
			--h;
			diam = max(diam, mx + len);
			mx = max(mx, len);
		}
	return mx;
}

void solve() {
	cin >> n >> a >> b >> da >> db, --a, --b;

	adj.assign(n, {});
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	h = diam = 0;
	dfs(a);
	if (2 * da >= min(diam, db) || dist <= da) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
