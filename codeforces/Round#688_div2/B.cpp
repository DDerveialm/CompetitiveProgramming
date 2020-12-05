#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	for (int i{0}; i + 1 < n; ++i)
		ans += abs(v[i] - v[i + 1]);

	long long rm{0};
	for (int i{0}; i < n; ++i) {
		if (i == 0) rm = max(rm, abs(v[0] - v[1]));
		else if (i == n - 1) rm = max(rm, abs(v[n - 2] - v[n - 1]));
		else if (signbit(v[i] - v[i - 1]) == signbit(v[i] - v[i + 1]))
			rm = max(rm, 2 * min(abs(v[i] - v[i - 1]), abs(v[i] - v[i + 1])));
	}

	cout << ans - rm << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
