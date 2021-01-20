#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> c(n, 0);
	queue<int> qu{}; qu.push(0);
	while (!qu.empty()) {
		int u; // take a vertex that is connected to white
		do {
			u = qu.front(), qu.pop();
		} while (!qu.empty() && c[u]);
		if (c[u]) break;

		c[u] = 1;
		for (auto& v : adj[u]) {
			if (c[v]) continue;
			c[v] = -1;
			for (auto& w : adj[v]) if (!c[w]) qu.push(w);
		}
	}

	if (any_of(c.begin(), c.end(), [](const int& x) {return x == 0;})) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << count_if(c.begin(),  c.end(), [](const int& x) {return x == 1;}) << '\n';
		for (int i{0}; i < n; ++i) if (c[i] == 1) cout << i + 1 << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
