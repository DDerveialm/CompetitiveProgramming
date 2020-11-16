#include <iostream>

using namespace std;

void solve() {
	int n, k, s;
	cin >> n >> k >> s;
	cout << k - 1 + min(n + 1, k - s + n - s + 1) << '\n';
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
