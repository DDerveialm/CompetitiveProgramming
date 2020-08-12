#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> F(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> F[i][j];
	/* method 1 */
/*
	vector<vector<int>> UL(n, vector<int>(m));
	vector<vector<int>> UR(n, vector<int>(m));
	vector<vector<int>> DL(n, vector<int>(m));
	vector<vector<int>> DR(n, vector<int>(m));
	// upper left
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (i == 0 || j == 0 || F[i - 1][j] != F[i][j] || F[i][j - 1] != F[i][j]) UL[i][j] = 1;
			else UL[i][j] = min(UL[i - 1][j], UL[i][j - 1]) + 1;
	// upper right
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < m; ++j)
			if (i == n - 1 || j == 0 || F[i + 1][j] != F[i][j] || F[i][j - 1] != F[i][j]) UR[i][j] = 1;
			else UR[i][j] = min(UR[i + 1][j], UR[i][j - 1]) + 1;
	// down left
	for (int i = 0; i < n; ++i)
		for (int j = m - 1; j >= 0; --j)
			if (i == 0 || j == m - 1 || F[i - 1][j] != F[i][j] || F[i][j + 1] != F[i][j]) DL[i][j] = 1;
			else DL[i][j] = min(DL[i - 1][j], DL[i][j + 1]) + 1;
	//down right
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			if (i == n - 1 || j == m - 1 || F[i + 1][j] != F[i][j] || F[i][j + 1] != F[i][j]) DR[i][j] = 1;
			else DR[i][j] = min(DR[i + 1][j], DR[i][j + 1]) + 1;

	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans += min(min(UL[i][j], UR[i][j]), min(DL[i][j], DR[i][j]));
*/
	/* method 2 */
	vector<vector<int>> dp(n, vector<int>(m)); // dp[i][j] is the number of pattern with (i, j) being the bottom-most.
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (i == 0 || i == 1 || j == 0 || j == m - 1
			|| F[i - 1][j - 1] != F[i][j] || F[i - 1][j + 1] != F[i][j]
			|| F[i - 1][j] != F[i][j] || F[i - 2][j] != F[i][j])
				dp[i][j] = 1;
			else
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j + 1]), dp[i - 2][j]) + 1;
			ans += dp[i][j];
		}
			
	cout << ans << endl;
	return 0;
}
