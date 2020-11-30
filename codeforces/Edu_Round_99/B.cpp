#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int x;
	cin >> x;

	int k{static_cast<int>(sqrt(2 * x))}, p{k * (k + 1) / 2};
	while (p < x) p += ++k;
	if (p - x == 1) cout << k + 1 << '\n';
	else cout << k << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
