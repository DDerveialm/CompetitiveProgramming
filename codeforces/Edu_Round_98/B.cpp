#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long n, mx{0}, s{0};
	cin >> n;
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		mx = max(mx, x);
		s += x;
	}

	n -= 1;
	if (s <= mx * n) cout << n * mx - s << '\n';
	else cout << n - ((s - 1) % n + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
