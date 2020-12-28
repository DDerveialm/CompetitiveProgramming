#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> r(n + 1);
	for (int i{1}; i <= n; ++i) cin >> r[i], r[i] += r[i - 1];

	int m;
	cin >> m;
	vector<int> b(m + 1);
	for (int i{1}; i <= m; ++i) cin >> b[i], b[i] += b[i - 1];

	cout << *max_element(r.begin(), r.end()) + *max_element(b.begin(), b.end()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
