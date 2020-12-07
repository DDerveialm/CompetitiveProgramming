#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> cnt(n + 1, 0);
	int tot{0};
	for (auto& x : v) {
		cin >> x;
		if (!cnt[x]) ++tot;
		++cnt[x];
	}

	vector<int> ans(n + 1, 0);
	ans[1] = (tot == n);
	ans[n] = (cnt[1] >= 1);

	int l{0}, r{n - 1};
	for (int i{1}; i < n; ++i) {
		if (cnt[i] != 1 || (v[l] != i && v[r] != i) || cnt[i + 1] == 0) break;

		if (v[l] == i) ++l;
		else --r;
		ans[n - i] = 1;
	}
	for (int i{1}; i <= n; ++i) cout << ans[i];
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
