#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int k{n / 2};
	if (n & 1) cout << 2 * (k + 1) * (k + 2) << '\n';
	else cout << (k + 1) * (k + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
