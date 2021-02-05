#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	for (auto& x : c) cin >> x;

	vector<int> ans(m, -1);

	vector<stack<int>> vs(n + 1);
	for (int i{0}; i < m; ++i) vs[c[i]].push(i);

	for (int i{0}; i < n; ++i) {
		if (a[i] == b[i]) continue;

		auto& s{vs[b[i]]};
		if (s.empty()) {
			cout << "NO\n";
			return ;
		}
		ans[s.top()] = i, s.pop();
	}

	if (ans[m - 1] == -1) {
		for (int i{0}; i < n; ++i)
			if (b[i] == c[m - 1]) ans[m - 1] = i;
	}
	if (ans[m - 1] == -1) {
		cout << "NO\n";
		return ;
	}

	for (int i{m - 2}; i >= 0; --i)
		if (ans[i] == -1) ans[i] = ans[m - 1];

	cout << "YES\n";
	for (auto& x : ans) cout << x + 1 << ' ';
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
