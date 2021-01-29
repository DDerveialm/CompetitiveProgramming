#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 3> a;
	for (auto& x : a) cin >> x;

	sort(a.begin(), a.end());
	do {
		if (a[0] * a[1] == a[2]) {
			cout << "YES\n";
			for (auto& x : a) cout << x << ' ';
			cout << '\n';
			return ;
		}
	} while (next_permutation(a.begin(), a.end()));

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
