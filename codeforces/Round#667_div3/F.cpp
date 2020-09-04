#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void solve() {
	int n, k;
	string s{};
	char a, b;
	cin >> n >> k >> s >> a >> b;

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, numeric_limits<int>::min())));
	dp[0][0][0] = 0;
	for (int i{0}; i < n; ++i) { // first i characters of s
		int c0{s[i] == a};
		int c1{s[i] == b};
		int c2{a == b};
		for (int j{0}; j <= k; ++j) { // use j moves
			for (int cnt{0}; cnt <= n; ++cnt) { // number of character a
				dp[i + 1][j][cnt + c0] = max(dp[i + 1][j][cnt + c0], dp[i][j][cnt] + (c1 ? cnt : 0));
				if (j != k) {
					dp[i + 1][j + 1][cnt + 1] = max(dp[i + 1][j + 1][cnt + 1], dp[i][j][cnt] + (c2 ? cnt : 0));
					dp[i + 1][j + 1][cnt + c2] = max(dp[i + 1][j + 1][cnt + c2], dp[i][j][cnt] + cnt);
				}
			}
		}
	}

	int ans{0};
	for (int j{0}; j <= k; ++j)
		for (int cnt{0}; cnt <= n; ++cnt)
			ans = max(ans, dp[n][j][cnt]);
	cout << ans << endl;
}

void solve2() {
	int n, k;
	string s, t;
	cin >> n >> k >> s >> t;
	auto s0{s};
	int ans{0};
	for (int b0{0}; b0 <= k; ++b0) { // times that substitute s[i] to t[0]
		auto e0 = k - b0; // s[i] to t[1]
		for (int x0{0}; x0 <= b0; ++x0) { // times that s[i] == t[1] and changes to t[0]
			for (int y0{0}; y0 <= e0; ++y0) { // s[i] == t[0] and becomes t[1]
				auto b = b0, e = e0, x = x0, y = y0;
				s = s0;

				for (int i{0}; i < n && b; ++i) {
					if (s[i] == t[0]) {
					} else if (s[i] != t[1]) {
						s[i] = t[0];
						--b;
					} else if (x > 0) {
						s[i] = t[0];
						--x;
						--b;
					}
				}
				if (x) goto break_x_loop;

				for (int j{n - 1}; j >= 0 && e; --j) {
					if (s[j] == t[1]) {
					} else if (s[j] != t[0]) {
						s[j] = t[1];
						--e;
					} else if (y > 0) {
						s[j] = t[1];
						--y;
						--e;
					}
				}
				if (y) break;

				int cnt{0}, times{0};
				for (int i{0}; i < n; ++i) {
					if (s[i] == t[1]) cnt += times;
					if (s[i] == t[0]) ++times;
				}
				ans = max(ans, cnt);
			}
		}
		break_x_loop: ;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve2();

	return 0;
}
