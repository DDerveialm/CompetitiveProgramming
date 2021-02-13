#include <iostream>

using namespace std;

void solve() {
	long long n, m;
	cin >> n >> m;

	long long ans{0};
	for (int i{1}; (m - 1) * i + 1 <= n; ++i) {
		ans += n - ((m - 1) * i + 1) + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
