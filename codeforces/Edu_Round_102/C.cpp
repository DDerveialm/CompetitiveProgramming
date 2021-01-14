#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	int n, k;
   	cin >> n >> k;

	vector<int> ans(k); iota(ans.begin(), ans.end(), 1);
	reverse(ans.begin() + k - 1 - (n - k), ans.end());

	for (auto& x : ans) cout << x << ' ';
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
