#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i{0}; i < n; ++i) {
		string s;
		cin >> s;
		for (auto& c : s) v[i] |= (1 << (c - 'A'));
	}

	vector<vector<int>> c(n, vector<int>(n, n));
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j)
			if (v[i] & v[j]) c[i][j] = 1, c[j][i] = 1;
	for (int k{0}; k < n; ++k)
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < n; ++j)
				if (c[i][k] + c[k][j] < c[i][j])
					c[i][j] = c[i][k] + c[k][j];

	while (q--) {
		int x, y;
		cin >> x >> y, --x, --y;
		if (c[x][y] >= n) cout << "-1";
		else cout << c[x][y] + 1;
		cout << " \n"[q == 0];
	}
}

void solve2() {
	int n, q;
	cin >> n >> q;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> c(26, vector<int>(26, 26));
	for (auto& x : v)
		for (int i{0}; i < x.size(); ++i)
			for (int j{i + 1}; j < x.size(); ++j)
				c[x[i] - 'A'][x[j] - 'A'] = c[x[j] - 'A'][x[i] - 'A'] = 1;
	for (int i{0}; i < 26; ++i) c[i][i] = 0;
	for (int k{0}; k < 26; ++k)
		for (int i{0}; i < 26; ++i)
			for (int j{0}; j < 26; ++j)
				if (c[i][k] + c[k][j] < c[i][j])
					c[i][j] = c[i][k] + c[k][j];

	while (q--) {
		int x, y;
		cin >> x >> y, --x, --y;
		int ans{26};
		for (auto& a : v[x])
			for (auto& b : v[y])
				ans = min(ans, c[a - 'A'][b - 'A']);

		if (ans >= 26) cout << "-1";
		else cout << ans + 2;
		cout << " \n"[q == 0];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve2();
	}
	return 0;
}
