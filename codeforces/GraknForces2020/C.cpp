#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	double x{0}, y{l}, ans{0};
   	int i{0}, j{n - 1}, sx{1}, sy{1};
	while (i <= j) {
		double t1{(v[i] - x) / sx};
		double t2{(y - v[j]) / sy};
		if (t1 <= t2) {
			x = v[i];
			++sx;
			++i;
			y -= t1 * sy;
			ans += t1;
		} else {
			y = v[j];
			++sy;
			--j;
			x += t2 * sx;
			ans += t2;
		}
	}

	ans += (y - x) / (sx + sy);
	cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
