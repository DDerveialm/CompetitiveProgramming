#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	bool ans{false};

	vector<long long> c1(n), c2(n);
	c1[0] = v[0];
	for (int i{1}; i < n; ++i) c1[i] = v[i] - c1[i - 1];

	if (c1[n - 1] == 0 && all_of(c1.begin(), c1.end(), [](const long long& x) {return x >= 0;})) // no swap
		ans = true;


	auto same_parity = [](const int& a, const int& b) {
		return (a & 1) == (b & 1);
	};

	for (int i{0}; i < n; ++i) {
		if (same_parity(i, n - 1)) c2[i] = c1[i] - c1[n - 1];
		else c2[i] = c1[i] + c1[n - 1];
	}


	int l{n - 2}, r{0};
	while (l > 0 && c2[l] >= 0) --l;
	while (r < n - 2 && c1[r] >= 0) ++r;

	for (int i{l}; i <= r; ++i) { // swap(v[i], v[i + 1])
		long long d{v[i + 1] - v[i]};
		if (c1[i] + d < 0) continue;

		if (same_parity(i, n - 1)) {
		   if (c1[n - 1] + 2 * d == 0) ans = true;
		} else {
		   if (c1[n - 1] - 2 * d == 0) ans = true;
		}
	}

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
