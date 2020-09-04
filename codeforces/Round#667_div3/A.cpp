#include <iostream>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	cout << (abs(a - b) + 9) / 10 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
