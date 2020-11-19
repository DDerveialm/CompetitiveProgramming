#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int cnt1{}, cnt2{0}, ans{0};
	for (auto& x : s) {
		if (x == '(') ++cnt1;
		if (x == ')' && cnt1) --cnt1, ++ans;
		if (x == '[') ++cnt2;
		if (x == ']' && cnt2) --cnt2, ++ans;
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
