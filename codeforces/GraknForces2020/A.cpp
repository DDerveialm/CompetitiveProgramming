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
#include <limits>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (auto& x : v) cin >> x[0];
	for (auto& x : v) cin >> x[1];
	for (auto& x : v) cin >> x[2];

	int last{-1};
	for (int i{0}; i < n - 1; ++i)
		for (int j{0}; j < 3; ++j)
			if (v[i][j] != last) {
				cout << v[i][j] << ' ';
				last = v[i][j];
				break;
			}
	for (int j{0}; j < 3; ++j)
		if (v[n - 1][j] != last && v[n - 1][j] != v[0][0]) {
			cout << v[n - 1][j] << ' ';
			break;
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
