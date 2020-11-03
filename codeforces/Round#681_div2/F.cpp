#include <iostream>
#include <vector>
#include <set>

using namespace std;

constexpr int M{998244353};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n), idx(n), b(k);
	set<int> s{};
	for (int i{0}; i < n; ++i) cin >> v[i], --v[i], idx[v[i]] = i;
	for (auto& x : b) cin >> x, --x, s.insert(x);
	
	int ans{1};
	for (int i{0}; i < k; ++i) {
		int c{0};
		auto l{idx[b[i]] - 1}, r{idx[b[i]] + 1};
		if (l >= 0 && s.find(v[l]) == s.end()) ++c;
		if (r < n && s.find(v[r]) == s.end()) ++c;
		ans *= c;
		if (!ans) break;
		ans %= M;
		s.erase(b[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
