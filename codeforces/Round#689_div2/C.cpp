#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
   	vector<double> e(n);
	for (auto& x : v) cin >> x, --x;
	for (int i{0}; i < m; ++i) {
		int r;
	   	double p;
		cin >> r >> p, --r;
		e[r] = 1.d - (1.d - e[r]) * (1.d - p);
	}
	e[0] = 1.d;

	double ans{0.d}, rmd{1.d};
	for (int i{n - 1}; i >= 0; --i) {
		ans += rmd * e[i];
		rmd *= (1.d - e[i]);
		if (v[i] != i) break;
	}

	cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
