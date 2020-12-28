#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> sp{};
	set<int> skip{};
	int a{n};
	while (a > 2) {
		int b{static_cast<int>(ceil(sqrt(a)))};
		sp.emplace_back(a, b), sp.emplace_back(a, b);
		skip.insert(a);
		a = b;
	}
	
	vector<pair<int, int>> ans{};
	for (int i{3}; i <= n; ++i) {
		if (skip.find(i) != skip.end()) continue;
		ans.emplace_back(i, i + 1);
	}

	cout << ans.size() + sp.size() << '\n';
	for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
	for (auto& [x, y] : sp) cout << x << ' ' << y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
