#include <iostream>

using namespace std;

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	if (n > m) swap(n, m);

	for (int i{1}; i <= p / i; ++i)
		if ((p % i) == 0 && i <= n && (p / i) <= m) {
			cout << "YES\n";
			return ;
		}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
