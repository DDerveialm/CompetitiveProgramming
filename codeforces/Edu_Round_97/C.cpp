#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;
	sort(v.begin(), v.end());

	vector<vector<int>> dp(n, vector<int>(2 * n, 200 * 200));
	for (int j{0}; j < 2 * n; ++j) dp[0][j] = abs(v[0] - j);
	for (int i{1}; i < n; ++i)
		for (int j{1}; j < 2 * n; ++j) {
			auto t{*min_element(dp[i - 1].begin(), dp[i - 1].begin() + j)};
			dp[i][j] = t + abs(v[i] - j);
		}

	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
