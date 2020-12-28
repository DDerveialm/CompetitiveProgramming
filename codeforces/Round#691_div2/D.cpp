#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	int A{0}, B{0};
	for (int i{1}; i <= n; ++i) cin >> a[i] >> b[i], A += a[i], B += b[i];

	vector<vector<int>> dp0(n + 1, vector<int>(A + 1, -B));
	vector<vector<int>> dp1(n + 1, vector<int>(A + 1, -B));
	for (int i{1}; i <= n; ++i) {
		dp0[0][0] = 0;
		for (int k{1}; k <= i; ++k)
			for (int t{0}; t <= A; ++t) {
				dp1[k][t] = dp0[k][t];
				if (t >= a[i]) dp1[k][t] = max(dp1[k][t], dp0[k - 1][t - a[i]] + b[i]);
			}
		swap(dp0, dp1);
	}

	for (int k{1}; k <= n; ++k) {
		double ans{0};
		for (int t{0}; t <= A; ++t)
			ans = max(ans, min(static_cast<double>(t), dp0[k][t] / 2.d + B / 2.d));
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
