#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n), lk(n);
	for (auto& x : vec) cin >> x;
	for (auto& x : lk) cin >> x;

	vector<int> mv{};
	for (int i{0}; i < n; ++i)
		if (!lk[i]) mv.push_back(vec[i]);
	sort(mv.rbegin(), mv.rend());
	
	int j{0};
	for (int i{0}; i < n; ++i) {
		if (lk[i]) cout << vec[i] << " ";
		else cout << mv[j++] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
