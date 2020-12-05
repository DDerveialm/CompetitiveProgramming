#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> bottom(n), left(m);
	for (auto& x : bottom) cin >> x;
	for (auto& x : left) cin >> x;

	int ans{0}, i{0};
	for (auto& x : bottom) {
		while (i < m && left[i] < x) ++i;
		if (i < m && left[i] == x) ++ans;
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
