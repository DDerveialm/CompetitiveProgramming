#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>

#define fi first
#define se second

using namespace std;

void solve() {
	array<int, 6> s;
	for (auto& x : s) cin >> x;
	int n;
	cin >> n;
	vector<pair<int, int>> v{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		for (auto& y : s) v.emplace_back(x - y, i);
	}
	sort(v.begin(), v.end());

	int ans{numeric_limits<int>::max()}, j{0};
	vector<int> ck(n, 0);
	int cnt{0};
	for (int i{0}; i < v.size(); ++i) {
		while (j < v.size() && cnt < n) { // find until every fret occurs in [v[i].fi:v[j].fi].
			if (!ck[v[j].se]++) ++cnt;
			++j;
		}
		if (cnt < n) break; // impossible
		ans = min(ans, v[j - 1].fi - v[i].fi);
		if (!--ck[v[i].se]) --cnt;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
