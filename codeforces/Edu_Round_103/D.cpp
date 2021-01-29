#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<int> L(n, 1), R(n, 1);
	for (int i{1}; i < n; ++i) // alternating from left
		if (v[i] != v[i - 1]) L[i] = L[i - 1] + 1;
	for (int i{n - 2}; i >= 0; --i) // ... from right
		if (v[i] != v[i + 1]) R[i] = R[i + 1] + 1;

	for (int i{0}; i <= n; ++i) {
		int ans{1};
		if (i - 1 >= 0 && v[i - 1] == 'L') ans += L[i - 1];
		if (i < n && v[i] == 'R') ans += R[i];

		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
