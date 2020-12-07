#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

#define fi first
#define se second

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (auto& x : v) cin >> x.fi >> x.se;

	auto dist = [](const pair<int, int>& x, const pair<int, int>& y) {
		return abs(x.fi - y.fi) + abs(x.se - y.se);
	};

	for (int i{0}; i < n; ++i) {
		bool flag{true};
		for (int j{0}; j < n; ++j)
			if (dist(v[i], v[j]) > k) flag = false;

		if (flag) {
			cout << "1\n";
			return ;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
