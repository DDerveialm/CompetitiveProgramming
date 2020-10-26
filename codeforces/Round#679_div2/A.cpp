#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i) {
		if (i % 2 == 0) cout << v[i + 1];
		else cout << -1 * v[i - 1];
		cout << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
