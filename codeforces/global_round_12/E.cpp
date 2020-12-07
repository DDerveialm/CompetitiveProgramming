#include <iostream>
#include <vector>
#include <utility>

#define fi first
#define se second

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> c(n, vector<int>(n, n));
	vector<pair<int, int>> e(m);
	for (int i{0}; i < n; ++i) c[i][i] = 0;
	for (auto& x : e) {
		int b;
		cin >> x.fi >> x.se >> b, --x.fi, --x.se;
		c[x.fi][x.se] = 1;
		c[x.se][x.fi] = (b ? -1 : 1);
	}

	for (int k{0}; k < n; ++k)
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < n; ++j)
				if (c[i][k] + c[k][j] < c[i][j])
					c[i][j] = c[i][k] + c[k][j];			
	
	int mx{-1}, s;
	for (int i{0}; i < n; ++i) {
		if (c[i][i] < 0) { // negative cycle
			cout << "NO\n";
			return ;
		}
		for (int j{0}; j < n; ++j)
			if (mx < c[i][j]) mx = c[i][j], s = i;
	}

	for (auto& x : e)
		if (c[s][x.fi] == c[s][x.se]) { // non-bipartite
			cout << "NO\n";
			return ;
		}

	cout << "YES\n";
	cout << mx << '\n';
	for (int i{0}; i < n; ++i)
		cout << c[s][i] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
