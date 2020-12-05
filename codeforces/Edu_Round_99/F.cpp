#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<string> dp(n + 1, ""s);
	for (int i{1}; i <= n; ++i) {
		string tmp{};
		char mn;
		if (v[i] == 'a' || v[i] - 'a' == k - 1) mn = 'a';
		else mn = v[i] - 1;
		// U or D
		dp[i] = dp[i - 1] + mn;

		if (i >= 2) {
			// L
			tmp = dp[i - 1] + v[i];
			swap(tmp[i - 2], tmp[i - 1]);
			dp[i] = min(dp[i], tmp);

		   	// RD or RU
			tmp = dp[i - 2] + mn + v[i - 1];
			dp[i] = min(dp[i], tmp);
		}
		if (i >= 3) { // RL
			tmp[i - 2] = v[i];
			swap(tmp[i - 3], tmp[i - 2]);
			dp[i] = min(dp[i], tmp);
		}
	}

	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
