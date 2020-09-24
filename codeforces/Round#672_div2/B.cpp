#include <iostream>
#include <vector>

using namespace std;

int msb(int x) {
	int r{0};
	while (x >>= 1) ++r;
	return r;
}

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(32, 0);
	long long ans{0};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		auto m{msb(x)};
		ans += cnt[m];
		++cnt[m];
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
