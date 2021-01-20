#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> p(n + 1);
	iota(next(p.begin()), p.end(), 1);

	stack<pair<int, int>> ans{};
	swap(p[1], p[n]);
	ans.emplace(1, n);
	long long time{static_cast<long long>(n - 1) * static_cast<long long>(n - 1)};

	for (int i{2}; i <= n - 1; ++i) {
		int j;
		if (n - i >= i - 1) j = n;
		else j = 1;

		swap(p[i], p[j]);
		time += static_cast<long long>(j - i) * static_cast<long long>(j - i);
		ans.emplace(i, j);
	}


	cout << time << '\n';

	for (int i{1}; i <= n; ++i) cout << p[i] << ' ';
	cout << '\n';

	cout << ans.size() << '\n';
	while (!ans.empty()) {
		auto [i, j]{ans.top()}; ans.pop();
		cout << i << ' ' << j << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
