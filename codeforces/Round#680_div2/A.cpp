#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	for (int i{0}; i < n; ++i)
		if (a[i] + b[i] > x) {
			cout << "NO\n";
			return ;
		}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
