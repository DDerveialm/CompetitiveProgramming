#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	cout << 9;
	for (int i{1}; i < n; ++i) cout << (7 + i) % 10;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
