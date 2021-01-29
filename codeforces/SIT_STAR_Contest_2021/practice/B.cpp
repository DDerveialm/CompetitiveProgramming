#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n == 0 || n % 3) cout << "-1\n";
	else {
		int x{n / 3};
		cout << x - 1 << ' ' << x << ' ' << x + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
