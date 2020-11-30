#include <iostream>
#include <array>
#include <limits>
#include <utility>

#define fi first
#define se second

using namespace std;

void adjust(pair<long long, long long>& p) {
	if (p.fi > p.se) swap(p.fi, p.se);
}

void solve() {
	using pll = pair<long long, long long>;
	array<pll, 4> a;
	for (auto& x : a) cin >> x.fi >> x.se;

	long long ans{numeric_limits<long long>::max()};

	auto calc = [](pll a, pll b, pll c, pll d) {
		long long cnt{0};
		pll x1{a.fi, b.fi}, x2{c.fi, d.fi}; // x range
		adjust(x1), adjust(x2);
		cnt += x1.se - x1.fi + x2.se - x2.fi;

		pll y1{min(a.se, b.se), min(c.se, d.se)}, y2{max(a.se, b.se), max(c.se, d.se)}; // y range
		adjust(y1), adjust(y2);
		cnt += y1.se - y1.fi + y2.se - y2.fi;

		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		pll lx{max(0ll, x2.fi - x1.se), max(x1.se - x2.fi, x2.se - x1.fi)},
		   	ly{max(0ll, y2.fi - y1.se), max(y1.se - y2.fi, y2.se - y1.fi)};
		if (lx > ly) swap(lx, ly);
		if (lx.se < ly.fi) cnt += (ly.fi - lx.se) * 2;

		return cnt;
	};

	ans = min(ans, calc(a[0], a[1], a[2], a[3]));
	ans = min(ans, calc(a[0], a[2], a[1], a[3]));
	ans = min(ans, calc(a[0], a[3], a[1], a[2]));

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
