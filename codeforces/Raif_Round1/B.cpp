#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	bool cL{true}, cR{true};
	for (auto& x : v) {
		cin >> x;
		if (x == '<') cR = false;
		else if (x == '>') cL = false;
	}

	int ans{0};
	if (cL || cR) ans = n;
	else {
		for (int i{0}; i < n; ++i)
			if (v[i] == '-' || v[(i + 1) % n] == '-') ++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
