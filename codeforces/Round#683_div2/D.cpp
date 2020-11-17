#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<char> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int ans{0};
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 4 - 2;
			else dp[i + 1][j + 1] = max(0, max(dp[i + 1][j] - 1, dp[i][j + 1] - 1));

			ans = max(ans, dp[i + 1][j + 1]);
		}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
