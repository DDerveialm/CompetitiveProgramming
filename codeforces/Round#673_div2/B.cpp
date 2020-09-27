#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, T;
	cin >> n >> T;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int flag{true};
	for (auto& x : v) {
		if (x * 2 < T) cout << "0 ";
		else if (x * 2 > T) cout << "1 ";
		else if (flag) cout << "0 ", flag = false;
		else cout << "1 ", flag = true;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
