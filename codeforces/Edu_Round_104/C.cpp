#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int m{n * (n - 1) / 2};

	vector<vector<int>> g(n, vector<int>(n, 0));
	
	for (int i{0}; i < n; ++i) {
		int t{m / n}, j{(i + 1) % n};
		while (t--) g[i][j] = 1, g[j][i] = -1, j = (j + 1) % n;
	}

	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) cout << g[i][j] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
