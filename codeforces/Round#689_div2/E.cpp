#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long k, l, r, t, x, y;
	cin >> k >> l >> r >> t >> x >> y;

	if (k < l || k > r) cout << "No\n";
	else if (x > y) {
		if (k + y > r) k -= x, --t;

		if (k < l) cout << "No\n";
		else if ((k - l) / (x - y) < t) cout << "No\n";
		else cout << "Yes\n";
	} else {
		vector<bool> was(x, false);
		while (t > 0) {
			if (was[k % x]) break; // form a cycle
			was[k % x] = true;

			auto moves{(k - l) / x}; // move as much as possible
			k -= moves * x;
			t -= moves;
			if (t <= 0) break;

			if (k + y <= r) k += y - x, --t; // add once
			else {
				cout << "No\n";
				return ;
			}
		}
		cout << "Yes\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
