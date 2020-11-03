#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long P{998244353};

vector<long long> fac(3e5 + 1);

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
	for (int i = 1; i < fac.size(); ++i)
		fac[i] = (fac[i - 1] * i) % P;
}

// Returns nCr % p using Fermat's little theorem.
long long nCr(int n, int r) {
	return fac[n] * power(fac[r], P - 2) % P * power(fac[n - r], P - 2) % P;
}

void solve() {
	int n;
	cin >> n;
	vector<long long> v(2 * n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	long long L{0}, R{0};
	for (int i{0}; i < n; ++i) L += v[i], R += v[n + i];
	cout << (nCr(2 * n, n) % P) * ((R - L) % P) % P << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	buildTable();	
	solve();

	return 0;
}
