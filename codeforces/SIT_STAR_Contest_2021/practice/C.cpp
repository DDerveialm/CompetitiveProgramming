#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int t0, t1, t2, ans;
	cin >> t0 >> t1 >> t2;

	if (t1 > t2) swap(t1, t2);

	if (t0 <= t1) ans = t2 - t0;
	else if (t0 >= t2) ans = t0 - t1;
	else ans = min(t0 - t1, t2 - t0) + (t2 - t1);

	cout << ans << '\n';
}

void solve2() {
	int t0, t1, t2, ans;
	cin >> t0 >> t1 >> t2;

	ans = abs(t1 - t0) + abs(t2 - t1);
	ans = min(ans, abs(t2 - t0) + abs(t1 - t2));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
