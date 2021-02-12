#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	long long x, y;
	cin >> x >> y;

	long long ans{0};
	for (long long k{1}; k <= x; ++k) {
		long long p{min(y + 1, x / k) - (k + 1)};
		if (p <= 0) break;
		ans += p;
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
