#include <iostream>

using namespace std;

void solve() {
	long long a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	long long t1 = max(a - n, x);
	long long t2 = max(b - n, y);
	if (t1 <= t2) {
		t2 = max(b - (n - (a - t1)), y);
	} else {
		t1 = max(a - (n - (b - t2)), x);
	}
	cout << t1 * t2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
