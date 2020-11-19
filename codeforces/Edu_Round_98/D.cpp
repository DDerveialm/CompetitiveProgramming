#include <iostream>
#include <array>

using namespace std;

constexpr long long P{998244353};

/* Iterative Function to calculate (x^y) % P in O(log y) */
long long power(long long x, long long y) { 
	long long ret{1};
	x = x % P;

	while (y > 0) {
		if (y & 1) ret = (ret * x) % P; 
		y >>= 1; 
		x = (x * x) % P;
	}
	return ret; 
}

long long modInv(long long x) {
	return power(x, P - 2);
}

void solve() {
	int n;
	cin >> n;
	array<long long, 3> f{0, 1, 1};
	for (int i{1}; i <= n; ++i) {
		f[0] = f[1];
		f[1] = f[2];
		f[2] = (f[0] + f[1]) % P;
	}
	cout << f[0] * modInv(power(2, n)) % P << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
