#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), a(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	for (int i{0}; i < n; ++i)
		a[(i * 2 + 1) % (n | 1)] = v[i];

	cout << (n - 1) / 2 << endl;
	for (auto& x : a) cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
