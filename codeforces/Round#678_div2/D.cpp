#include <iostream>
#include <vector>

#define fi first
#define se second

using namespace std;

namespace D {
	long long mx{0};
	vector<long long> v{};
	vector<vector<int>> adj{};

	pair<long long, int> dfs(int u) {
		if (adj[u].empty()) {
			mx = max(mx, v[u]);
			return {v[u], 1};
		}

		long long s{v[u]};
		int leaf{0};
		for (auto& v : adj[u]) {
			auto p{dfs(v)};
			s += p.fi;
			leaf += p.se;
		}
		mx = max(mx, (s + leaf - 1) / leaf);
		return {s, leaf};
	}

	void solve() {
		int n;
		cin >> n;
		v.assign(n, {}), adj.assign(n, {});

		for (int i{1}; i < n; ++i) {
			int u;
			cin >> u, --u;
			adj[u].push_back(i);
		}
		for (auto& x : v) cin >> x;
	
		dfs(0);
		cout << mx << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	D::solve();

	return 0;
}
