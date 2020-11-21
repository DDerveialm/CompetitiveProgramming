#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans{0};
	if (n > 1) {
		if (n & 1) --n, ++ans;
		if (n > 2) n = 2, ++ans; // div
		--n, ++ans; // sub
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
