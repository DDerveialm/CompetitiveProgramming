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

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));

	int d{static_cast<int>(v.size())}, ans{1};
	if (k == 1) {
		if (d != 1) ans = -1;
	} else {
		d -= k;
		if (d > 0) ans += (d + k - 2) / (k - 1);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
