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

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& e : vec)
		cin >> e, --e;

	long long ans = 0;
	vector<vector<int>> times(n, vector<int> (n, 0));
	for (int j = n - 3; j > 0; --j) {
		int k = j + 1;
		for (int l = k + 1; l < n; ++l)
			++times[vec[k]][vec[l]];

		for (int i = 0; i < j; ++i)
			ans += times[vec[i]][vec[j]];
	}

	cout << ans << endl;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
