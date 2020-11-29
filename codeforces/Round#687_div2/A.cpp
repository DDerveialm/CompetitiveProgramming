#include <iostream>

using namespace std;

void solve() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	cout << max(r - 1, n - r) + max(c - 1, m - c) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
