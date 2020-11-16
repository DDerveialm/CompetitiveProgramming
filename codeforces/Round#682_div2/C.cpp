#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < m; ++j) {
			int x;
			cin >> x;
			if (((i + j) & 1) ^ (x & 1)) cout << x + 1 << ' ';
			else cout << x << ' ';
		}
		cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
