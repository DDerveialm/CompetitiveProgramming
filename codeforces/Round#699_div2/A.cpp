#include <iostream>
#include <string>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	string s;
	cin >> s;

	int l{0}, r{0}, u{0}, d{0};
	for (auto& x : s) {
		if (x == 'L') ++l;
		else if (x == 'R') ++r;
		else if (x == 'U') ++u;
		else if (x == 'D') ++d;
	}

	if (-1 * l <= x && x <= r && -1 * d <= y && y <= u) cout << "YES\n";
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
