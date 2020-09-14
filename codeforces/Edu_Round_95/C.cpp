#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 3, 0);
	for (int i{1}; i <= n; ++i) cin >> a[i];

	vector<int> dp(n + 4);
	dp[0] = 0;
	dp[1] = 1e9;
	for (int i{2}; i <= n + 3; ++i) {
		dp[i] = dp[i - 2] + a[i - 1];
		if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + a[i - 2]);
		if (i >= 4) dp[i] = min(dp[i], dp[i - 4] + a[i - 3] + a[i - 2]);
	}
	cout << dp[n + 3] << endl;
}

void solve2() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i{1}; i <= n; ++i) cin >> a[i];

	vector<array<int, 2>> dp(n + 1);
	dp[0][0] = 0;
   	dp[0][1] = 1e9;
	for (int i{1}; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1];
		if (i >= 2) dp[i][0] = min(dp[i][0], dp[i - 2][1]);

		dp[i][1] = dp[i - 1][0] + a[i];
		if (i >= 2) dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 1] + a[i]);
	}
	cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve2();

	return 0;
}
