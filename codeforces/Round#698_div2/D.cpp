#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	long long k;
	cin >> k;

	long long x1, g{0};
	cin >> x1;
	for (int i{1}; i < n; ++i) {
		long long x;
		cin >> x;
		g = gcd(g, x - x1);
	}

	if ((k - x1) % g) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
