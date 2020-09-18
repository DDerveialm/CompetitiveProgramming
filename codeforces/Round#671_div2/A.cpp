#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	bool R_has_odd{false}, B_has_even(false);
	for (int i{1}; i <= n; ++i) {
		char c;
		cin >> c;
		if (i & 1 && c & 1) R_has_odd = true;
		if (!(i & 1) && !(c & 1)) B_has_even = true;
	}
	if ((n & 1 && R_has_odd) || (!(n & 1) && !B_has_even)) cout << 1 << endl;
	else cout << 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
