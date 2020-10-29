#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	char a, b, c, d;
	for (int i{1}; i <= n * n; ++i) {
		char v;
		cin >> v;
		if (i == 2) a = v;
		else if (i == n + 1) b = v;
		else if (i == n * n - n) c = v;
		else if (i == n * n - 1) d = v;
	}
	vector<pair<int, int>> ans{};
	if (a == b) {
		if (c == a) ans.emplace_back(n - 1, n);
		if (d == a) ans.emplace_back(n, n - 1);
	} else if (c == d) {
		if (a == c) ans.emplace_back(1, 2);
		if (b == c) ans.emplace_back(2, 1);
	} else {
		if (a != '0') ans.emplace_back(1, 2);
		else ans.emplace_back(2, 1);
		if (c != '1') ans.emplace_back(n - 1, n);
		else ans.emplace_back(n, n - 1);
	}


	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
