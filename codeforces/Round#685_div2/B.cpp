#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	while (q--) {
		bool ans{false};
		int l, r;
		cin >> l >> r, --l, --r;
		for (int i{l - 1}; i >= 0; --i) if (v[i] == v[l]) ans = true;
		for (int i{r + 1}; i < n; ++i) if (v[i] == v[r]) ans = true;
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
