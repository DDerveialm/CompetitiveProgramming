#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(n);
	for (auto& [l, t] : v) cin >> l >> t, t += l;

	vector<pair<int, int>> event{};
	for (auto& [l, r] : v) event.emplace_back(l, 1), event.emplace_back(r, -1);
	sort(event.begin(), event.end());
	n = event.size();

	vector<int> ar(n, 0), lv(n, 0), time(n);
	for (int i{0}; i < n; ++i) {
		if (i - 1 >= 0) ar[i] = ar[i - 1], lv[i] = lv[i - 1];

		auto& [tm, tp]{event[i]};
		time[i] = tm;
		if (tp == 1) ++ar[i];
		else if (tp == -1) ++lv[i];
	}

	int ans{0};

	int r{0};
	for (int l{0}; l < n; ++l) {
		while (r < n && time[r] - time[l] <= m) ++r;
		ans = max(ans, ar[r - 1] - (l == 0 ? 0 : lv[l - 1]));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
