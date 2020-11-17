#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n, c0, c1, h;
	cin >> n >> c0 >> c1 >> h;
	c0 = min(c0, h + c1);
	c1 = min(c1, h + c0);

	int ans{0};
	string s;
	cin >> s;
	for (auto& x : s) {
		if (x == '0') ans += c0;
		else ans += c1;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
