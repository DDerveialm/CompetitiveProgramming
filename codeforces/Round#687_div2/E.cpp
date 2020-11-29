#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k, ++k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	long long ans{0}, ss{0};
	for (int i{0}; i < n; ++i) ans += i * static_cast<long long>(v[i]), ss += v[i];

	for (int i{0}; (ss -= v[i]) < 0; ++i) // sliding
		if (i % k != k - 1) ans -= ss;

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
