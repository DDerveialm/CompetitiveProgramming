#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	reverse(v.begin(), v.end());
	int cnt{0};
	for (auto& x : v) {
		if (x == ')') ++cnt;
		else break;
	}

	if (cnt > n - cnt) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
