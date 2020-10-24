#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long w, n;
	cin >> w >> n;
	vector<long long> v(w + 1);
	for (int i{1}; i <= w; ++i) cin >> v[i];
	sort(v.begin() + 1, v.end());

	vector<long long> presum(w + 2);
	for (int i{1}; i <= w; ++i) presum[i] = presum[i - 1] + v[i];

	long long ans{w * n};
	for (int i{1}; i <= w; ++i) {
		long long moves{0};
		int l{0}, r{i};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (v[i] - v[m] <= n / 2) r = m;
			else l = m;
		}
		moves += l * n - (l * v[i] - presum[l]); // [1:l]
		moves += (i - 1 - l) * v[i] - (presum[i - 1] - presum[l]); // [r:i-1]

		l = i, r = w + 1;
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (v[m] - v[i] <= n / 2) l = m;
			else r = m;
		}
		moves += (presum[l] - presum[i]) - (l - i) * v[i]; // [i+1:l]
		moves += (w - l) * n - ((presum[w] - presum[l]) - (w - l) * v[i]); // [r:w]
		ans = min(ans, moves);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
