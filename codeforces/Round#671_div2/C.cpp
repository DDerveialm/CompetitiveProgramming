#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;

	bool has_x{false}, all_x{true};
	int sum{0};
	vector<int> v(n);
	for (auto& e : v) {
		cin >> e;
		if (e == x) has_x = true;
		else all_x = false;
		sum += e;
	}

	if (all_x) cout << 0 << endl;
	else if (has_x || sum == x * n) cout << 1 << endl;
	else cout << 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
