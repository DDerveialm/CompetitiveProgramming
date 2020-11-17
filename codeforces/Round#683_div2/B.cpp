#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int s{0};
	vector<int> v(n * m);
	for (auto& x : v) cin >> x, s += x;

	int ans{s};
	sort(v.begin(), v.end());
	for (int i{0}; i + 1 < v.size(); i += 2) {
		s -= 2 * (v[i] + v[i + 1]);
		ans = max(ans, s);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
