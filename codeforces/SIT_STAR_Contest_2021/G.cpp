#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int m{static_cast<int>(s.size())};
	vector<vector<long long>> dp(2, vector<long long>(m));

	long long ans{0};
	for (int i{0}; i < n; ++i) {
		dp[1][0] = 1;
		for (int j{1}; j < m; ++j)
			dp[1][j] = dp[0][j - 1] + dp[1][j - 1];

		ans += dp[1][m - 1];
		swap(dp[1], dp[0]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
