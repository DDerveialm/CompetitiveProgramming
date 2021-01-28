#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int last{v[0]}, cnt{1}, ans{1};
	for (int i{1}; i < n; ++i) {
		if (v[i] == last) ++cnt;
		else last = v[i], cnt = 1;
		ans = max(ans, cnt);
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
