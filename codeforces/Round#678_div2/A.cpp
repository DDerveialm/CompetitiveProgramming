#include <iostream>

using namespace std;

void solve() {
	int n, m, s{0};
	cin >> n >> m;
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s += x;
	}
	if (s == m) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
