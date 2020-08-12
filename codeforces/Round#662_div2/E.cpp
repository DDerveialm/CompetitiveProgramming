#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<string> scroll(n);
	for (auto& a : scroll)
		cin >> a;

	vector<vector<string>> sub(2, vector<string>(2e4));
	vector<vector<int>> dp(2, vector<int>(2e4));

	for (int j = 0; j < scroll[0].length() + 1; ++j) {
		dp[1][j] = j + 1;
		sub[1][j].reserve(scroll[0].length());
		for (int k = 0; k < scroll[0].length(); ++k)
			if (j != k) sub[1][j] += scroll[0][k];
	}
	sort(sub[1].begin(), sub[1].begin() + scroll[0].length() + 1);

	for (int i = 1; i < n; ++i) {
		sub[1].swap(sub[0]);
		for (int j = 0; j < scroll[i].length() + 1; ++j) {
			sub[1][j] = ""s;
			sub[1][j].reserve(scroll[i].length());
			for (int k = 0; k < scroll[i].length(); ++k)
				if (j != k) sub[1][j] += scroll[i][k];
		}
		sort(sub[1].begin(), sub[1].begin() + scroll[i].length() + 1);

		dp[1].swap(dp[0]);
		int last = -1; // record last left bound
		for (int j = 0; j < scroll[i].length() + 1; ++j) {
			dp[1][j] = 0;
			int l = last, r = scroll[i - 1].length() + 1; // [l:r)
			while (l < r - 1) {
				int m = (l + r) / 2;
				if (sub[1][j].compare(sub[0][m]) >= 0) l = m;
				else r = m;
			}
			last = l;
			
			if (l != -1) dp[1][j] = dp[0][l];
			if (j != 0) dp[1][j] += dp[1][j - 1];
			if (dp[1][j] >= MOD) dp[1][j] -= MOD;
		}
	}

	cout << dp[1][scroll[n - 1].length()] << endl;
	return 0;
}
