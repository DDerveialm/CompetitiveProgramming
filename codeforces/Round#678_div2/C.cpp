#include <iostream>

using namespace std;

constexpr long long mod{static_cast<long long>(1e9) + 7};

void solve() {
	int n, x, p;
	cin >> n >> x >> p;

	int l{0}, r{n}, c1{-1}, c2{0};
	while (l < r) {
		int m{(l + r) / 2};
		if (m <= p) l = m + 1, ++c1;
		else r = m, ++c2;
	}
	long long res{1};
	for (int i{0}; i < c1; ++i) res *= (x - 1 - i), res %= mod;
	for (int i{0}; i < c2; ++i) res *= (n - x - i), res %= mod;
	for (int i{0}; i < n - 1 - c1 - c2; ++i) res *= (n - 1 - c1 - c2 - i), res %= mod;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
