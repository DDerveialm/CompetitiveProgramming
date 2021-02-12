#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mtx(n, vector<int>(m));
	int LCM{1};
	for (auto& v : mtx)
		for (auto& x : v) cin >> x, LCM = lcm(LCM, x);

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < m; ++j) {
			int ans{LCM};
			if ((i + j) & 1) ans += mtx[i][j] * mtx[i][j] * mtx[i][j] * mtx[i][j];
			cout << ans << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
