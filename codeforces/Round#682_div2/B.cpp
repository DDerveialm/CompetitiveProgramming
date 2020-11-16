#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	for (int i{1}; i < n; ++i)
		if (v[i] == v[i - 1]) {
			cout << "YES\n";
			return ;
		}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
