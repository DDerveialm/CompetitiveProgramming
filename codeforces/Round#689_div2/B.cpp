#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mtx(n + 1, vector<char>(m + 1));
	for (int i{0}; i < n; ++i)
		for (int j{1}; j <= m; ++j)
			cin >> mtx[i][j];

	long long ans{0};
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 2));
	for (int i{n - 1}; i >= 0; --i)
		for (int j{1}; j <= m; ++j) {
			if (mtx[i][j] != '*') continue;
			dp[i][j] = 1;
			if (mtx[i + 1][j] == '*')
				dp[i][j] += min(dp[i + 1][j - 1], dp[i + 1][j + 1]);

			ans += dp[i][j];
		}

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
