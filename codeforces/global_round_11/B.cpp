#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans{2 * min(n, (int)count(v.begin(), v.end(), 'W') + k)};


	vector<int> gap{};
	int l{n};
	for (int i{0}; i < n; ++i)
		if (v[i] == 'W') {
			if (l < i) gap.emplace_back(i - l);
			l = i + 1;
		}
	if (ans) ans -= gap.size() + 1;

	sort(gap.begin(), gap.end());
	for (auto& x : gap) {
		if (k < x) break;
		k -= x;
		ans += 1;
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
