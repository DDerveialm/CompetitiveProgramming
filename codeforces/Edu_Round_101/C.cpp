#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> h(n);
	for (auto& x : h) cin >> x;

	bool ans{true};
	vector<pair<long long, long long>> dp(n);
	dp[0] = {h[0], h[0]};
	for (int i{1}; i < n; ++i) {
		auto& [ll, lh]{dp[i - 1]}; // last lowest / highest
		auto& [cl, ch]{dp[i]}; // current ...
		cl = max(ll - (k - 1), h[i]);
		ch = min(lh + (k - 1), h[i] + (k - 1));
		if (ch < cl) ans = false;
	}
	if (dp[n - 1].first > h[n - 1]) ans = false;

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
