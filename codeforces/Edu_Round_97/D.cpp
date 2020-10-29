#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{1}, cnt{1}, nxt{0};
	for (int i{1}; i < n; ++i) {
		if (v[i] < v[i - 1])
			if (!--cnt) ++ans, cnt = nxt, nxt = 0;
		++nxt;
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
