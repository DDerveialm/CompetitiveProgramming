#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> k(n), c(m);
	for (auto& x : k) cin >> x, --x;
	for (auto& x : c) cin >> x;

	sort(k.rbegin(), k.rend());

	long long ans{0};
	int i{0};
	for (auto& x : k) {
		if (x > i) ans += c[i++];
		else ans += c[x];
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
