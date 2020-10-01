#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> r(n), s(m);
	for (auto& x : r) cin >> x.first >> x.second;
	for (auto& x : s) cin >> x.first >> x.second;

	vector<pair<int, int>> d{{static_cast<int>(1e6 + 2), 0}, {0, 0}}; // no move up and no move right
	for (auto& x : r)
		for (auto& y : s) d.emplace_back(max(0, y.first + 1 - x.first), max(0, y.second + 1 - x.second));
	sort(d.begin(), d.end(), greater<pair<int, int>>());

	d[0].first = d[1].first;
	for (auto it{d.begin() + 1}; it != d.end(); ++it) {
		it -> second = max(it -> second, prev(it) -> second);
		it -> first = next(it) -> first + it -> second;
	}
	cout << min_element(d.begin(), d.end()) -> first << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
