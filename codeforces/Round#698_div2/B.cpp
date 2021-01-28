#include <iostream>
#include <array>

using namespace std;

void solve() {
	int q, d;
	cin >> q >> d;

	array<int, 10> a{};
	fill(a.begin(), a.end(), d * 10);

	for (int i{1}; i <= 9; ++i) {
		int x{d * i};
		a[x % 10] = min(a[x % 10], x);
	}

	while (q--) {
		long long x;
		cin >> x;

		if (x >= a[x % 10]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
