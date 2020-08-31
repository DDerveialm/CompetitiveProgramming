#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<int, 26> count {};
	for (int i{}; i < n; ++i) {
		string s;
		cin >> s;
		for (auto& c : s)
			++count[static_cast<int> (c - 'a')];
	}
	bool ans {true};
	for (auto& e : count)
		if (e % n) {
				ans = false;
				break;
			}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
