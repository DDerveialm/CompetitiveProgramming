#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n * k);
	for (auto& x : v) cin >> x;

	int l{(n - 1) / 2}, r{n - l};

	long long ans{0};
	for (int i{k * l}; i < v.size(); i += r) ans += v[i];
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
