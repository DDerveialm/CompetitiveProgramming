#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << abs(x2 - x1) + abs(y2 - y1) + ((x2 == x1) || (y2 == y1) ? 0 : 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
