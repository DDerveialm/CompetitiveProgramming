#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k, --k;

	auto cyc = [&n](int x) {
		x = (((x % n) + n) % n);
		return x;
	};

	int ans;
	if ((n & 1) == 0) ans = cyc(0 + k);
	else {
		int p{n / 2}; // period they meet
		int a{cyc(n - 1 - (k / p) * p)}, b{cyc(a + 1)}; // a is next to b
		ans = cyc(b + (k % p));
	}

	cout << ans + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
