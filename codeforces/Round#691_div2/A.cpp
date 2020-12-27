#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, cnt{0};
	cin >> n;
	vector<char> r(n);
	for (auto& x : r) cin >> x;
	for (int i{0}; i < n; ++i) {
		char b;
		cin >> b;
		if (r[i] > b) ++cnt;
		else if (r[i] < b) --cnt;
	}
	if (cnt > 0) cout << "RED\n";
	else if (cnt < 0) cout << "BLUE\n";
	else cout << "EQUAL\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
