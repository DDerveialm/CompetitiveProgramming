#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // std::inner_product

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 2);
	v[0] = v[n + 1] = 0;
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> r(n + 2, 0);
	for (int i{1}; i <= n; ++i) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) r[i] = 1;
		if (v[i] < v[i - 1] && v[i] < v[i + 1]) r[i] = -1;
	}

	long long ans{inner_product(v.begin(), v.end(), r.begin(), 0ll)};
	cout << ans << '\n';
	while (q--) {
		int a, b;
		cin >> a >> b;
		vector<int> idx{a - 1, a, a + 1, b - 1, b, b + 1};
		sort(idx.begin(), idx.end());
		idx.resize(distance(idx.begin(), unique(idx.begin(), idx.end())));

		auto rm_old = [&](int i) { ans -= v[i] * r[i]; };
		for (auto& i : idx) rm_old(i);

		swap(v[a], v[b]);
		auto recalc = [&](int i) {
			if (i == 0 || i == n + 1) return ;
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) r[i] = 1;
			else if (v[i] < v[i - 1] && v[i] < v[i + 1]) r[i] = -1;
			else r[i] = 0;
			ans += v[i] * r[i];
		};
		for (auto& i : idx) recalc(i);

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
