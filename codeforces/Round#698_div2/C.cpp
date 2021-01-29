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
		if (d[i] != d[i + 1] || (i + 2 < 2 * n && d[i] == d[i + 2])) {
			cout << "NO\n";
			return ;
		}

	long long c{0};
	for (int i{0}; i < 2 * n; i += 2) {
		int k{2 * n - i};
		if (d[i] <= c || (d[i] - c) % k) {
			cout << "NO\n";
			return ;
		}
		d[i] = (d[i] - c) / k;
		c += 2 * d[i];
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
