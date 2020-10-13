#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool close(const pair<int, pair<int, int>>& e1, const pair<int, pair<int, int>> e2) {
	if (abs(e1.second.first - e2.second.first) + abs(e1.second.second - e2.second.second) <= abs(e2.first - e1.first)) return true;
	else return false;
}

void solve() {
	int r, n;
	cin >> r >> n;
	vector<pair<int, pair<int, int>>> v(n + 1);
	v[0] = {0, {1, 1}};
	for (int i{1}; i <= n; ++i)
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	
	int ans{0};
	vector<int> dp(n + 1, -1e6);
	dp[0] = 0;
   	int pre{0}, pmx{static_cast<int>(-1e6)};
	for (int i{1}; i <= n; ++i) {
		while (pre < i && v[i].first - v[pre].first >= 2 * r - 2) pmx = max(pmx, dp[pre]), ++pre;
		dp[i] = pmx + 1;
		for (int j{pre}; j < i; ++j)
			if (close(v[i], v[j])) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
