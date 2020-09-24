#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 2);
	v[0] = v[n + 1] = 0;
	for (int i{1}; i <= n; ++i) cin >> v[i];

	long long ans{0};
	for (int i{1}; i <= n; ++i) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) ans += v[i];
		if (v[i] < v[i - 1] && v[i] < v[i + 1]) ans -= v[i];
	}
	cout << ans << endl;
}

void solve2() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];
   	vector<long long> dp1(n + 1), dp2(n + 1);
	dp1[0] = -1e9;
	dp2[0] = 0;
	for (int i{1}; i <= n; ++i) {
		dp2[i] = max(dp2[i - 1], dp1[i - 1] - v[i]);
		dp1[i] = max(dp1[i - 1], dp2[i - 1] + v[i]);
	}
	cout << dp1[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
