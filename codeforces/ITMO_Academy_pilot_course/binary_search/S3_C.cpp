#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto check = [&v, &k](int d) {
		int cnt{1};
		int last{v[0]};
		for (int i{1}; i < v.size(); ++i) {
			if (v[i] >= last + d) {
				++cnt;
				last = v[i];
			}
		}
		if (cnt >= k) return true;
		else return false;
	};
	int l{0}, r{static_cast<int>(1e9) + 1};
	while (l < r - 1) {
		int m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
