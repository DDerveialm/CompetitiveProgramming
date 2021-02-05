#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (auto& x : h) cin >> x;

	int ans;
	while (k--) {
		int i;
		for (i = 0; i + 1 < n; ++i)
			if (h[i] < h[i + 1]) {
				++h[i];
				ans = i;
				break;
			}
		if (i + 1 == n) break;
	}

	cout << (k == -1 ? ans + 1 : -1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
