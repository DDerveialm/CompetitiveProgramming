#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<char>> m(n, vector<char>(n));
	array<int, 3> cntx{}, cnto{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			cin >> m[i][j];
		   	if (m[i][j] == 'X') ++cntx[(i + j) % 3];
		   	if (m[i][j] == 'O') ++cnto[(i + j) % 3];
		}

	int mn{n * n}, o, x;
	for (int i{0}; i < 3; ++i)
		for (int j{0}; j < 3; ++j) {
			if (j == i) continue;
			if (cntx[i] + cnto[j] < mn)
				mn = cntx[i] + cnto[j], x = i, o = j;
		}
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			if (m[i][j] == 'X' && (i + j) % 3 == x) m[i][j] = 'O';
			if (m[i][j] == 'O' && (i + j) % 3 == o) m[i][j] = 'X';
		}

	for (auto& x : m) {
		for (auto& y : x) cout << y;
		cout << '\n';
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
