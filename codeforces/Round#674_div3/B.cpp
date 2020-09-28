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
	int n, m;
	cin >> n >> m;
	vector<array<int, 4>> v(n);
	bool ans{false};
	for (auto& x : v) {
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		if (x[1] == x[2]) ans = true;
	}

	if (!(m & 1) && ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
