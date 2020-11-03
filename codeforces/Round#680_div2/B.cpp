#include <iostream>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(a + b, c + d) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
