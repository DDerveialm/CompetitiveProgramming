#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), a(n);
	for (auto& x : v) cin >> x;

	int j{0};
	sort(v.begin(), v.end());
	for (int i{1}; i < n; i += 2) a[i] = v[j++];
	for (int i{0}; i < n; i += 2) a[i] = v[j++];

	int cnt{0};
	for (int i{1}; i < n - 1; ++i)
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) ++cnt;

	cout << cnt << endl;
	for (auto& x : a) cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
