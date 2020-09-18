#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	auto check = [&v, &k](long long s) {
		int n{0};
		long long cnt{0};
		for (auto& x : v) {
			cnt += x;
			if (cnt > s) {
				cnt = x;
				++n;
			}
		}
		++n;
		if (n <= k) return true;
		else return false;
	};
	long long l{*max_element(v.begin(), v.end())}, r{static_cast<long long>(1e14) + 1};
	while (l < r - 1) {
		long long m{(l + r) / 2};
		if (check(m - 1)) r = m;
		else l = m;
	}
	cout << l << endl;
	return 0;
}
