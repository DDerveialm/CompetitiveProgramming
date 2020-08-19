#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <bitset>

using namespace std;

int mask(string s) {
	int m = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '1')
			m |= (1 << i);
	return m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	string origin, ideal;
	cin >> origin >> ideal;
	vector<int> p(k);
	for (int i = 0; i < k; ++i) p[i] = i;
	vector<vector<int>> dp(2, vector<int> (1 << k, 0));
	for (int i = 0; i < (1 << k); ++i) {
		dp[0][i] = 1e9;
		dp[1][i] = -1e9;
	}
	dp[0][mask(origin)] = 0;
	dp[1][mask(ideal)] = 0;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		swap(p[a], p[b]);
		string x(k, '0'), y(k, '0');
		for (int j = 0; j < k; ++j) {
			x[p[j]] = origin[j];
			y[p[j]] = ideal[j];
		}
		dp[0][mask(x)] = min(i, dp[0][mask(x)]);
		dp[1][mask(y)] = i;
	}

	int c1 = count(origin.begin(), origin.end(), '1'), c2 = count(ideal.begin(), ideal.end(), '1');
	int Max = -1;
	pair<int, int> ans;
	for (int i = (1 << k) - 1; i >= 0; --i) {
		if (dp[1][i] - dp[0][i] >= m) {
			int cb = k - (c1 + c2 - 2 * __builtin_popcount(i));
			if (cb > Max) {
				Max = cb;
				ans = {dp[0][i] + 1, dp[1][i]};
			}
		}
		for (int j = 0; j < k; ++j) {
			if (i & (1 << j)) {
				dp[0][i ^ (1 << j)] = min(dp[0][i ^ (1 << j)], dp[0][i]);
				dp[1][i ^ (1 << j)] = max(dp[1][i ^ (1 << j)], dp[1][i]);
			}
		}
	}
	cout << Max << endl;
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
