#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, d;
   	cin >> n >> d;

	bool ans{true};

	vector<int> v(n);
	for (auto& x : v) {
		cin >> x;
		if (x > d) ans = false;
	}
	
	sort(v.begin(), v.end());
	if (v[0] + v[1] <= d) ans = true;

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
