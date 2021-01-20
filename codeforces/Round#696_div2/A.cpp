#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<char> b(n);
	for (auto& x : b) cin >> x;

	cout << "1";
	char last{1 + b[0]};
	for (int i{1}; i < n; ++i) {
		if (1 + b[i] != last) cout << "1", last = 1 + b[i];
		else cout << "0", last = 0 + b[i];
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
