#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	int mx{0}, p{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] < mx) p = i + 1;
		mx = max(mx, v[i]);
	}
	v.resize(p);
	v.push_back(x);

	auto s{v};
	sort(s.begin(), s.end());

	int ans{0};
	for (int i{0}; i < p; ++i)
		if (v[i] != s[i]) {
			if (v[i] <= v[p]) {
				cout << "-1\n";
				return ;
			}
			++ans;
			swap(v[i], v[p]);
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
