#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> m(n, vector<int>(n));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) cin >> m[i][j], --m[i][j];

	array<int, 3> o{0, 0, 0};
	int vx{1}, vy{0}, vz{2};
	while (k--) {
		char op;
		cin >> op;
		if (op == 'R') --o[vx];
		else if (op == 'L') ++o[vx];
		else if (op == 'D') --o[vy];
		else if (op == 'U')	++o[vy];
		else if (op == 'I') swap(vx, vz);
		else if (op == 'C')	swap(vy, vz);
	}
	
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			array<int, 3> p{i, j, m[i][j]};
			int x{p[vx] - o[vx]};
			int y{p[vy] - o[vy]};
			int z{p[vz] - o[vz]};
			ans[(y % n + n) % n][(x % n + n) % n] = (z % n + n) % n;
		}

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) cout << ans[i][j] + 1 << ' ';
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
