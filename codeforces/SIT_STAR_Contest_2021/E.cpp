#include <iostream>
#include <string_view>

using namespace std;

void solve() {
	long long x, y;
	cin >> x >> y;
	if (x < y) swap(x, y);

	long long ans{0};
	while (y) {
		ans += x / y;
		x %= y;
		swap(x, y);
	}

	cout << ((x == 1 && y == 0) ? ans - 1 : -1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
