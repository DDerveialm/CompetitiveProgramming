#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<bool> v(n);
	for (int i{0}; i < n; ++i) {
		char c; cin >> c;
		v[i] = c - '0';
	}

	vector<pair<int, int>> ans{};
	int i{0};
	while (a--) {
		bool flag{false};
		while (i + 1 < n && !flag) {
			if (!v[i] && !v[i + 1]) {
				v[i] = v[i + 1] = true;
				ans.emplace_back(i, i + 1);
				flag = true;
			}
			++i;
		}
		if (!flag) {
			cout << "NO\n";
			return ;
		}
	}
	i = 0;
	while (b--) {
		bool flag{false};
		while (i < n && !flag) {
			if (!v[i]) {
				ans.emplace_back(i, -1);
				flag = true;
			}
			++i;
		}
		if (!flag) {
			cout << "NO\n";
			return ;
		}
	}

	cout << "YES\n";
	for (auto& [x, y] : ans) {
		cout << x + 1;
		if (y != -1) cout << ' ' << y + 1;
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
