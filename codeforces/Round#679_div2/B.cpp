#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> t(n, vector<int>(m));
	for (auto& x : t)
		for (auto& y : x) cin >> y;

	for (int i{0}; i < n; ++i) {
		int k;
		cin >> k;
		for (auto& x : t) {
			bool find{false};
			for (auto& y : x)
				if (y == k) {
					find = true;
					break;
				}
			if (find) {
				for (auto& y : x) cout << y << ' ';
				cout << '\n';
				break;
			}
		}
	}

	for (int i{1}; i < m; ++i) // do nothing
		for (int j{0}; j < n; ++j) {
			int k;
			cin >> k;
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
