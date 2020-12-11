#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i{0}; i < n; ++i)
		cout << char('a' + i % 3);
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
