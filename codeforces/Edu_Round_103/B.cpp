#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long c{v[0]}, ans{0};
	for (int i{1}; i < n; ++i) {
		if (100 * v[i] > c * k) {
			long long _c{(100 * v[i] + k - 1) / k};
			ans += _c - c;
			c = _c;
		}
		c += v[i];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
