#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	long long mx{0}, sum{0};
	for (auto& e : v) mx += (e + x - 1) / x, sum += e;

	cout << (sum + x - 1) / x << ' ' << mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
