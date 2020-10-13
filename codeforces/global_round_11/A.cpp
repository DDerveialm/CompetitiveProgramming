#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, s{0};
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, s += x;

	if (s < 0) sort(v.begin(), v.end());
	else if (s > 0) sort(v.rbegin(), v.rend());
	if (v[0] == 0 && v.size() != 1) swap(v[0], v[1]);

	if (s) {
		cout << "YES\n";
		for (auto& x : v) cout << x << " ";
		cout << '\n';
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
