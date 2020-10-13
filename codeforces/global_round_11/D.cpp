#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> ans{};
	while (!is_sorted(v.begin(), v.end())) {
		vector<int> ck(n + 1, 0);
		ck[0] = 1;
		int x{-1}, y, m;
		for (int i{0}; i < n; ++i) { // find x
			if (ck[v[i] - 1] == 0) {
				x = i;
				break;
			}
			ck[v[i]] = 1;
		}

		for (y = x + 1; y < n; ++y) if (v[y] == v[x] - 1) break; // find y

		for (m = x; v[m + 1] == v[m] + 1; ++m) ; // in order not to break sorted part

		vector<int> v2{};
		for (int i{y + 1}; i < n; ++i) v2.push_back(v[i]); // (y:n)
		for (int i{m + 1}; i <= y; ++i) v2.push_back(v[i]); // (m:y]
		for (int i{x}; i <= m; ++i) v2.push_back(v[i]); // [x:m]
		for (int i{0}; i < x; ++i) v2.push_back(v[i]); // [0,x)
		v = move(v2);
		
		vector<int> op{0};
		if (0 < x) op.push_back(x - 0), ++op[0];
		op.push_back(m + 1 - x), ++op[0];
		op.push_back(y - m), ++op[0];
		if (y + 1 < n) op.push_back(n - (y + 1)), ++op[0];
		ans.push_back(op);
	}

	cout << ans.size() << '\n';
	for (auto& x : ans) {
		for (auto& y : x) cout << y << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
