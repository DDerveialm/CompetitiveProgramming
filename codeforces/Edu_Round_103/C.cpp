#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> c(n), a(n), b(n);
	for (auto& x : c) cin >> x;
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	long long len{c[n - 1] - 1}, ans{0};
	for (int i{n - 1}; i >= 1; --i) {
		if (a[i] > b[i]) swap(a[i], b[i]);

		len += 2;
		ans = max(ans, len + b[i] - a[i]);

		if (a[i] == b[i]) len = c[i - 1] - 1;
		else len += (a[i] - 1) + (c[i - 1] - b[i]), len = max(len, c[i - 1] - 1);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
