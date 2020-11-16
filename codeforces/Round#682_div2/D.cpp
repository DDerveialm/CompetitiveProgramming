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
#include <functional>
#include <iomanip>

#define fi first
#define se second

using namespace std;

void solve() {
	int n, all{0};
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, all ^= x;

	if (all && (n & 1) == 0) {
		cout << "NO\n";
		return ;
	}

	vector<tuple<int, int, int>> ans{};
	for (int i{1}; i + 2 <= n; i += 2)
		ans.emplace_back(i, i + 1, i + 2);
	for (int i{1}; i + 1 < n - 2; i += 2)
		ans.emplace_back(i, i + 1, n);

	cout << "YES\n" << ans.size() << '\n';
	for (auto& x : ans)
		cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
