#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, ans{0};
	cin >> n;
	vector<bool> ck(2 * n + 2, false);

	while (n--) {
		int x;
		cin >> x;
		if (!ck[x]) ++ans, ck[x] = true;
		else if (!ck[x + 1]) ++ans, ck[x + 1] = true;
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
