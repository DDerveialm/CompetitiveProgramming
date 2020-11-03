#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 2), b(k + 2);
	int ans{0};

	a[0] = -n, a[n + 1] = 1e9;
	for (int i{1}; i <= n; ++i)
		cin >> a[i], a[i] -= i; // increasing -> non-decreasing

	b[0] = 0, b[k + 1] = n + 1;
	for (int i{1}; i <= k; ++i) {
		cin >> b[i];
		if (a[b[i]] < a[b[i - 1]]) ans = -1;
	}

	if (!ans) {
		for (int i{0}; i + 1 < k + 2; ++i) {
			vector<int> v{a[b[i]]};
			for (int j{b[i] + 1}; j < b[i + 1]; ++j) {
				if (a[j] < a[b[i]] || a[j] > a[b[i + 1]]) continue;
				if (a[j] >= v.back()) v.push_back(a[j]);
				else *upper_bound(v.begin(), v.end(), a[j]) = a[j];
			}
			int LNDS{static_cast<int>(v.size()) - 1}; // longest non-decreasing subsequence
			ans += b[i + 1] - b[i] - 1 - LNDS;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
