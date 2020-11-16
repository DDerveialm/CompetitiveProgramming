#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int msb(int x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return (x + 1) >> 1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<int, int>> ans{};
	for (int l{0}; l + 2 < n; ++l) {
		long long s{v[l + 1]};
		int r{l + 2};

		auto u{msb(v[l]) * 2};
		while (s <= u && r < n) {
			if (s == (v[l] ^ v[r])) ans.emplace_back(l, r);
			s += v[r];
			++r;
		}
	}
	for (int r{n - 1}; r - 2 >= 0; --r) {
		long long s{v[r - 1]};
		int l{r - 2};

		auto u{msb(v[r]) * 2};
		while (s <= u && l >= 0) {
			if (s == (v[l] ^ v[r])) ans.emplace_back(l, r);
			s += v[l];
			--l;
		}
	}

	// for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
	sort(ans.begin(), ans.end());
	cout << distance(ans.begin(), unique(ans.begin(), ans.end())) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
