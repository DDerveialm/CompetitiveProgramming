#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int q, d;
	cin >> q >> d;

	vector<int> v{};
	for (int i{0}; i < d; ++i) v.push_back(10 * i + d);

	vector<bool> dp(10 * d, false);
	dp[0] = true;
	for (int i{1}; i < dp.size(); ++i)
		for (auto& n : v)
			if (i - n >= 0 && dp[i - n]) dp[i] = true;

	while (q--) {
		long long x;
		cin >> x;

		if (x >= 10 * d || dp[x]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
