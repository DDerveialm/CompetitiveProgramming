#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;
	cout << s.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
