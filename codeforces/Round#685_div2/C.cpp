#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	array<int, 26> a{}, b{};
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		++a[c - 'a'];
	}
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		++b[c - 'a'];
	}

	bool ans{true};
	int cum{0};
	for (int i{0}; i < 26; ++i) {
		if (a[i] + cum >= b[i]) {
			cum += a[i] - b[i];
			if (cum % k) ans = false;
		} else ans = false;
	}
	if (ans) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
