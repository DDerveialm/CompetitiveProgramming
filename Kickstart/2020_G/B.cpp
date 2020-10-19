#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
	long long ans{0};
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= n; ++j) {
			long long c;
			cin >> c;
			dp[i][j] = dp[i - 1][j - 1] + c;
			ans = max(ans, dp[i][j]);
		}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
