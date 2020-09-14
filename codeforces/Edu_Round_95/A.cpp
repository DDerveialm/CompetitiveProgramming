#include <iostream>

using namespace std;

void solve() {
	long long x, y, k;
	cin >> x >> y >> k;

	long long stk{k - 1 + y * k};
	--x;
	cout << (stk + (x - 1)) / x + k << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
