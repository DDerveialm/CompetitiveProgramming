#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 3> x, y;
	for (int i{0}; i < 3; ++i) cin >> x[i] >> y[i];

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	cout << (x[0] == x[1] ? x[2] : x[0]) << ' ' << (y[0] == y[1] ? y[2] : y[0]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
