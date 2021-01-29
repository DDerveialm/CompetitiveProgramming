#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	array<int, 3> a, b;
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << inner_product(a.begin(), a.end(), b.begin(), 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
