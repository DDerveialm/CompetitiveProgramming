#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (auto& e : x) cin >> e;
	for (int i{0}; i < n; ++i) { int y; cin >> y; }
	sort(x.begin(), x.end());

	vector<int> l(n), r(n);
	int j{0};
	for (int i{0}; i < n; ++i) {
		while (x[i] - x[j] > k) ++j;
		l[i] = i - j + 1;
		if (i) l[i] = max(l[i], l[i - 1]);
	}
	j = n - 1;
	for (int i{n - 1}; i >= 0; --i) {
		while (x[j] - x[i] > k) --j;
		r[i] = j - i + 1;
		if (i != n - 1) r[i] = max(r[i], r[i + 1]);
	}

	int ans{1}; // when n == 1, ans = 1.
	for (int i{1}; i < n; ++i) {
		ans = max(ans, l[i - 1] + r[i]);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
