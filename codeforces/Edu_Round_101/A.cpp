#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	if ((s.front() == ')') || (s.back() == '(') || (s.size() & 1)) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
