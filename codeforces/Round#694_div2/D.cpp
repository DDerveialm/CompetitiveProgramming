#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int mx{static_cast<size_t>(1e6)};

vector<int> tb(mx + 1, 1);
void build_table() {
	for (int i{2}; i * i <= mx; ++i) {
		int ps{i * i}; // perfect square
		for (int j{ps}; j <= mx; j += ps)
			tb[j] = ps;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, x /= tb[x];

	sort(v.begin(), v.end());
	v.push_back(-1);

	int ans0{0}, ans1{0}, cnt{1};
	for (int i{0}; i < n; ++i) {
		if (v[i + 1] == v[i]) ++cnt;
		else {
			ans0 = max(ans0, cnt);
			if (v[i] == 1 || (cnt & 1) == 0) ans1 += cnt;
			cnt = 1;
		}
	}
	ans1 = max(ans1, ans0);

	int q;
	cin >> q;
	while (q--) {
		long long w;
		cin >> w;
		if (w == 0) cout << ans0 << '\n';
		else cout << ans1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	build_table();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
