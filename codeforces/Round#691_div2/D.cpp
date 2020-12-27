#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	int A{0}, B{0};
	for (int i{1}; i <= n; ++i) cin >> a[i] >> b[i], A += a[i], B += b[i];

	vector<vector<int>> dp0(n + 1, vector<int>(A + 1, 0));
	vector<vector<int>> dp1(n + 1, vector<int>(A + 1, 0));
	vector<set<int>> r(n + 1);
	r[0].insert(0);
	for (int i{1}; i <= n; ++i) {
		for (int k{i}; k >= 1; --k) {
			for (auto& t : r[k]) dp1[k][t] = dp0[k][t];
			for (auto& t : r[k - 1]) dp1[k][t + a[i]] = max(dp1[k][t + a[i]], dp0[k - 1][t] + b[i]), r[k].insert(t + a[i]);
		}
		swap(dp0, dp1);
	}

	for (int k{1}; k <= n; ++k) {
		double ans{0};
		for (auto& t : r[k])
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
