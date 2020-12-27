#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	long long t{0};
	for (auto& x : a) t = gcd(t, x - a[0]);

	for (auto& x : b) cout << gcd(a[0] + x, t) << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
