#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	auto only_divide = [](int _a, int _b) {
		int res{0};
		while (_a) _a /= _b, ++res;
		return res;
	};

	int mx;
	if (b == 1) mx = 1 + only_divide(a, 2);
	else mx = only_divide(a, b);

	int ans{mx};
	for (int i{1}; i < mx; ++i) {
		ans = min(ans, i + only_divide(a, b + i));
	}

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
