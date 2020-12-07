#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), cnt(n + 1, 0);
	for (auto& x : v) cin >> x;

	int k{0};
	for (int i{0}; i < n; ++i) {
		if (i == 0 || i == n - 1) ++cnt[v[i]];
		if (i + 1 < n && v[i] == v[i + 1]) cnt[v[i]] += 2, ++k;
	}
	int mx{int(distance(cnt.begin(), max_element(cnt.begin(), cnt.end())))};

	int f{0};
	for (auto& x : v) if (x == mx) ++f;

	if (f + (f - 1) > n)  cout << "-1\n";
	else cout << max(cnt[mx] - 2, k) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
