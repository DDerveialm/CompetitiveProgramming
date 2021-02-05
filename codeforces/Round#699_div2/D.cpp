#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> adj(n, vector<char>(n));

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j)
			cin >> adj[i][j];

	if (m & 1) {
		cout << "YES\n";
		for (int i{0}; i <= m; ++i) cout << (i & 1) + 1 << ' '; // 1 2 1 2 1 ...
		cout << '\n';
		return ;
	}

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j)
			if (i != j && adj[i][j] == adj[j][i]) {
				cout << "YES\n";
				while (m) cout << i + 1 << ' ' << j + 1 << ' ', m -= 2;
				cout << i + 1 << '\n';
				return ;
			}


	for (int i{0}; i < n; ++i) {
		int in{-1}, out{-1};
		for (int j{0}; j < n; ++j) {
			if (adj[j][i] == 'a') in = j;	
			if (adj[i][j] == 'a') out = j;
		}
		if (in == -1 || out == -1) continue;

		cout << "YES\n";
		bool odd{(m / 2) & 1};
		if ((m / 2) & 1) {
			for (int k{1}; k <= m / 2; ++k)
				if (k & 1) cout << in + 1 << ' ';
				else cout << i + 1 << ' ';
			cout << i + 1 << ' ';
			for (int k{1}; k <= m / 2; ++k)
				if (k & 1) cout << out + 1 << ' ';
				else cout << i + 1 << ' ';
		} else {
			for (int k{1}; k <= m / 2; ++k)
				if (k & 1) cout << i + 1 << ' ';
				else cout << in + 1 << ' ';
			cout << i + 1 << ' ';
			for (int k{1}; k <= m / 2; ++k)
				if (k & 1) cout << out + 1 << ' ';
				else cout << i + 1 << ' ';
		}
		cout << '\n';
		return ;
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
