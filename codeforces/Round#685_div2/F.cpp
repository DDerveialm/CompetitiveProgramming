#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mtx(n, vector<int>(m));
	for (auto& x : mtx)
		for (auto& y : x) cin >> y;


	bool A{false};
	for (int d{0}; d <= n - 1 + m - 1; ++d) {
		int x{0};
		for (int i{max(0, d - (m - 1))}; i <= min(n - 1, d); ++i) {
			int j{d - i};
			x ^= mtx[i][j];
		}
		if (x) A = true;
	}
	if (A) cout << "Ashish\n";
	else cout << "Jeel\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
