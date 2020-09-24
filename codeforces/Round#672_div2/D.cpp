#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long P = 998244353;
vector<long long> fac(3e5 + 1);
vector<long long> Invfac(3e5 + 1);

/* Iterative Function to calculate (x^y) % P in O(log y) */
long long power(long long x, int y) { 
	long long ret{1};
	x = x % P;

	while (y > 0) {
		if (y & 1) 
			ret = (ret * x) % P; 
		y >>= 1; 
		x = (x * x) % P;
	}
    return ret; 
}

void buildTable() { 
	fac[0] = 1;
	Invfac[0] = power(1, P - 2);
	for (int i = 1; i < fac.size(); ++i) {
		fac[i] = (fac[i - 1] * i) % P;
		Invfac[i] = power(fac[i], P - 2);
	}
}

long long modInverse(long long n) {
	return power(n, P - 2);
}

// Returns nCr % p using Fermat's little theorem.
long long nCr(int n, int r) {
	return fac[n] * Invfac[r] % P * Invfac[n - r] % P;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(2 * n);
	for (int i{0}; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		v[2 * i] = {l, 1};
		v[2 * i + 1] = {r + 1, -1};
	}
	sort(v.begin(), v.end());

	int cnt{0};
	long long ans{0};
	for (auto& x : v) {
		if (x.second == 1)
			if (cnt >= k - 1) ans += nCr(cnt, k - 1), ans %= P;
		cnt += x.second;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	buildTable();
	solve();

	return 0;
}
