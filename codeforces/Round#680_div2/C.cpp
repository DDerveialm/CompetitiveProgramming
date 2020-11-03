#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long calc(long long p, long long q) {
	long long res{0}, pd{1};
	vector<bool> vis(ceil(sqrt(q)) + 1, false);
	for (long long i{2}; i < vis.size(); ++i) {
		if (vis[i]) continue;
		for (long long j{i * i}; j < vis.size(); j += i) vis[j] = true;

		if (q % i == 0) {
			auto t{p};
			while (t % i == 0) t /= i;
			res = max(res, t);

			t = q;
			while (t % i == 0) t /= i, pd *= i;
		}
	}
	pd = q / pd;
	if (pd > 1) { // big prime divisior
		while (p % q == 0) p /= pd;
		res = max(res, p);
	}
	return res;
}

void solve() {
	long long p, q;
	cin >> p >> q;
	if (p % q == 0) cout << calc(p, q) << '\n';
	else cout << p << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
