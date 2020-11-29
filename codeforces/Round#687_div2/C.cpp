#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void solve() {
	int n, p, k, x, y;
	cin >> n >> p >> k, --p;
	vector<char> v(n);
	for (auto& e : v) cin >> e;
	cin >> x >> y;

	int ans{numeric_limits<int>::max()};
	for (int i{0}; i < k; ++i) {
		int cnt{0};
		for (int j{n - 1 - i}; j >= p; j -= k) {
			if (v[j] == '0') ++cnt;
			ans = min(ans, cnt * x + (j - p) * y);
		}
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
