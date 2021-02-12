#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, q;
	long long k;
	cin >> n >> q >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> c(n);
	for (int i{1}; i < n; ++i) {
		c[i] = v[i + 1] - v[i - 1] - 1 - 1;
		c[i] += c[i - 1];
	}

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;
	
		if (l == r) {
			cout << k - 1 << '\n';
			continue;
		}

		long long ans{0};
		if (r - 1 >= l + 1) ans += c[r - 1] - c[l + 1 - 1];
		ans += k - v[r - 1] - 1; // ( v[r-1] : k ]
		ans += v[l + 1] - 1 - 1; // [ 1 : v[l+1] )
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
