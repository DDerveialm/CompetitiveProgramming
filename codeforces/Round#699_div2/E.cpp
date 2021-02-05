#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<int> l(n), r(n);
	for (int i{n - 1}; i >= 0; --i) l[v[i]] = i;
	for (int i{0}; i < n; ++i) r[v[i]] = i;

	vector<int> dp(n + 1); dp[n] = 0; // max num of unchanged
	vector<int> f(n, 0);
	for (int i{n - 1}; i >= 0; --i) {
		auto& c{v[i]};
		++f[c];
		dp[i] = dp[i + 1];
		if (i == l[c]) dp[i] = max(dp[i], f[c] + dp[r[c] + 1]);
		else dp[i] = max(dp[i], f[c]);
	}

	cout << n - dp[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
