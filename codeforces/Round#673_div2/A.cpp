#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	auto mn{min_element(v.begin(), v.end())};

	int ans{0};
	for (auto it{v.begin()}; it != v.end(); ++it) {
		if (it == mn) continue;
		ans += (k - *it) / *mn;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
