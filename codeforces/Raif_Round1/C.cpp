#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	int cntB{0}, del{0};
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (auto& c : s) {
		if (c == 'A') {
			if (cntB) --cntB, del += 2;
		} else ++cntB;
	}
	del += cntB - (cntB & 1);
	cout << s.size() - del << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
