#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (auto& [t, x] : v) cin >> t >> x;
	v.emplace_back(numeric_limits<long long>::max(), 0);

	int ans{0}, dir{1};
	long long T{0}, p{0};
	bool flag{false};
	for (int i{0}; i < n; ++i) {
		auto& [t, x]{v[i]};
		if (t >= T) {
			T = t + abs(x - p), dir = (x >= p ? 1 : -1), p = x;
		   	ans += flag, flag = true;
		} else {
			flag = false;

			auto& [t2, x2]{v[i + 1]};
			long long p1{p - dir * (T - t)};
			long long p2{p - dir * max(0ll, (T - t2))};
			if ((p1 <= x && x <= p2) || (p1 >= x && x >= p2)) ++ans;
		}
	}
	ans += flag;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
