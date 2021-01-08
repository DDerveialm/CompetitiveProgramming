#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto test = [&](int i) -> bool {
		if (!(i - 1 >= 0 && i + 1 < n)) return false;

		if (v[i] > v[i - 1] && v[i] > v[i + 1]) return true;
		if (v[i] < v[i - 1] && v[i] < v[i + 1]) return true;
		return false;
	};
	auto calc = [&](int i) -> int {
		int res{0};
		res += test(i - 1);
		res += test(i);
		res += test(i + 1);
		return res;
	};

	int tot{0}, eli{0}; // eliminate
	for (int i{1}; i + 1 < n; ++i) {
		tot += test(i);

		int r{v[i]}, a{calc(i)};
		{
			v[i] = v[i - 1];
			int b{calc(i)};
			eli = max(eli, a - b);
		}
		{
			v[i] = v[i + 1];
			int b{calc(i)};
			eli = max(eli, a - b);
		}
		v[i] = r;
	}

	cout << tot - eli << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
