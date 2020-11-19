#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), cnt(n, 0);
	for (auto& x : v) cin >> x, ++cnt[--x];

	int D{0};
	bool flag{false};
	for (int i{1}; i < n; ++i)
		if (cnt[D] < cnt[i]) D = i, flag = false;
		else if (cnt[D] == cnt[i]) flag = true;
	if (flag) {
		cout << n << '\n';
		return ;
	}

	set<int> s{};
	vector<vector<int>> pos(n);
	for (int i{0}; i < n; ++i)
		if (v[i] == D) s.insert(i);
		else pos[v[i]].push_back(i);

	vector<int> lst(2 * n + 1, -1);
	int ans{0};
	for (int i{0}; i < n; ++i) {
		if (pos[i].empty()) continue;

		vector<pair<int, int>> events{};
		for (auto& x : pos[i]) {
			for (int j{0}; j < 2; ++j) {
				auto it{s.lower_bound(x)};
				if (it != s.end())
					events.emplace_back(*it, 1), s.erase(it);
				it = s.lower_bound(x);
				if (it != s.begin())
					it = prev(it), events.emplace_back(*it, 1), s.erase(it);
			}
			events.emplace_back(x, -1);
		}
		events.emplace_back(n, 0); // to handle the case that subarray can take all the remaining
		sort(events.begin(), events.end());

		int sum{n}, mx{n}, mn{n};
		int prev{0};
		for (auto& x : events) {
			if (lst[sum] >= 0) ans = max(ans, x.fi - lst[sum]);
			else lst[sum] = prev;
			prev = x.fi + 1;
			sum += x.se;
			mx = max(mx, sum);
			mn = min(mn, sum);
		}

		for (int j{mn}; j <= mx; ++j) lst[j] = -1; // clear
		for (auto& x : events) if (x.se == 1) s.insert(x.fi); // put back
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
