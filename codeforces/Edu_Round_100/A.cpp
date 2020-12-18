#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((a + b + c) % 9 == 0) {
		int t{(a + b + c) / 9};
		if (a >= t && b >= t && c >= t) cout << "YES\n";
		else cout << "NO\n";
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
