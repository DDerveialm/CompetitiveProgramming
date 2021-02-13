#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<int> l(n);
	l[0] = (v[0] == '*' ? 0 : -1e6);
	for (int i{1}; i < n; ++i)
		if (v[i] == '*') l[i] = i;
		else l[i] = l[i - 1];

	vector<int> r(n);
	r[n - 1] = (v[n - 1] == '*' ? n - 1 : n + 1e6);
	for (int i{n - 2}; i >= 0; --i)
		if (v[i] == '*') r[i] = i;
		else r[i] = r[i + 1];

	for (int i{0}; i < n; ++i) cout << ((i - l[i] <= k || r[i] - i <= k) ? '*' : '.');
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
