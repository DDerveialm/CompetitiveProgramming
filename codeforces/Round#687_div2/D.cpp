#include <iostream>
#include <vector>

using namespace std;

int msb(int x) {
	int res{0};
	while (x >>= 1) ++res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), b(n);
	for (int i{0}; i < n; ++i) cin >> v[i], b[i] = msb(v[i]);
	
	for (int i{0}; i + 2 < n; ++i)
		if ((b[i] == b[i + 1]) && (b[i + 1] == b[i + 2])) {
			cout << "1\n";
			return ;
		}
	
	// short array
	int ans{n};
	for (int i{0}; i < n; ++i) {
		int x{0};
		for (int j{i}; j < n; ++j) {
			x ^= v[j];
			int y{0};
			for (int k{j + 1}; k < n; ++k) {
				y ^= v[k];
				if (x > y) ans = min(ans, k - i - 1);
			}
		}
	}
	if (ans == n) cout << "-1\n";
	else cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
