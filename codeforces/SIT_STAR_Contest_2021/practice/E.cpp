#include <iostream>

using namespace std;

void solve() {
	int k;
	cin >> k;

	long long x{k / 2}, y{k - x};
	cout << (x + 1) * (y + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
