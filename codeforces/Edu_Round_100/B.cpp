#include <iostream>

using namespace std;

int msb(int x) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return (x + 1) >> 1;
}

void solve() {
	int n;
	cin >> n;
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		cout << msb(x) << " \n"[i == n - 1];
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
