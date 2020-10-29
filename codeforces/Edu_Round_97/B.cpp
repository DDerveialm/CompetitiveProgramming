#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt{1};
	for (int i{1}; i < n; ++i)
		if (v[i] == v[i - 1]) ++cnt;
	cout << cnt / 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
