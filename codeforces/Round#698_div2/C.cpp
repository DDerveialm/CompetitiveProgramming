#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> d(2 * n);
	for (auto& x : d) cin >> x;

	sort(d.rbegin(), d.rend());
	for (int i{0}; i < 2 * n; i += 2)
		if (d[i] != d[i + 1]) {
			cout << "NO\n";
			return ;
		}

	long long c{0}, _x{-1};
	for (int i{0}; i < 2 * n; i += 2) {
		if (d[i] <= c) {
			cout << "NO\n";
			return ;
		}

		d[i] -= c;

		int _n{2 * n - i};
		long long x{d[i] / _n};
		if (d[i] % _n || x == _x) {
			cout << "NO\n";
			return ;
		}

		c += 2 * x;
		_x = x;
	}

	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
