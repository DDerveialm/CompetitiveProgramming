#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	auto mod = [](long long& x) {
		constexpr long long P{static_cast<long long>(1e9) + 7};
		x %= P;
		if (x < 0) x += P;
	};

	int n, k, q;
	cin >> n >> k >> q;
	vector<long long> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<vector<long long>> dp(k + 1, vector<long long>(n + 2));
	dp[0][0] = dp[0][n + 1] = 0;
	fill(dp[0].begin() + 1, dp[0].end() - 1, 1);
	for (int l{1}; l <= k; ++l)
		for (int i{1}; i <= n; ++i)
			dp[l][i] = dp[l - 1][i - 1] + dp[l - 1][i + 1], mod(dp[l][i]);

	vector<long long> cnt(n + 1, 0);
	for (int i{1}; i <= n; ++i) {
		for (int j{0}; j <= k; ++j)
			cnt[i] += dp[j][i] * dp[k - j][i], mod(cnt[i]);
	}

	long long ans{0};
	for (int i{1}; i <= n; ++i) ans += v[i] * cnt[i], mod(ans);

	while (q--) {
		int i, x;
		cin >> i >> x;

		ans -= v[i] * cnt[i];
		v[i] = x;
		ans += v[i] * cnt[i];
		mod(ans);

		cout << ans << '\n';
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
