#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;
	v.push_back('$');

	vector<int> seg{};
	int cnt{1};
	for (int i{1}; i <= n; ++i)
		if (v[i] != v[i - 1]) seg.push_back(cnt), cnt = 1;
		else ++cnt;

	int ans{0}, last_j{0};
	for (int i{0}; i < seg.size(); ++i) {
		++ans;
		int j{max(i, last_j)};
		for (; j < seg.size(); ++j)
			if (seg[j] > 1) {
				--seg[j];
				break;
			}
		if (j == seg.size()) ++i;
		last_j = j;
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
