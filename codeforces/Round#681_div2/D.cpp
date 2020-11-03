#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int l{v[0]}, r{0};
	for (int i{1}; i < n - 1; ++i) {
		if (v[i] < r) {
			cout << "NO\n";
			return ;
		}
		l = min(l, v[i] - r);
		r = v[i] - l;
	}
	if (r > v[n - 1]) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
