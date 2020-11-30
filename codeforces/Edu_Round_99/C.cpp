#include <iostream>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	cout << x - 1 << ' ' << y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
