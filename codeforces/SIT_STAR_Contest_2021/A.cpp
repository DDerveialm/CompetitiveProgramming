#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	cout << min((x - 1) * 20, (y - 1 + x - 1) * 5) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
