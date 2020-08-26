#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	int x;
	cin >> s >> x;
	string w(s.size(), '1');
	for (int i = 0; i < s.size(); ++i) {
		if (i - x >= 0 && s[i - x] == '0') w[i] = '0';
		if (i + x < s.size() && s[i + x] == '0') w[i] = '0';
	}
	bool flag = true;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			bool check = false;
			if (i - x >= 0 && w[i - x] == '1') check = true;
			if (i + x < w.size() && w[i + x] == '1') check = true;;
			if (!check) flag = false;
		}
	}
	if (flag) cout << w << endl;
	else cout << -1 << endl;
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
