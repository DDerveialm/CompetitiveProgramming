#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, k;
	cin >> n >> k;
	vector<long long> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	auto calc = [&n, &a, &b](long long x) {
		long long sum{0}, l{-1}, r{n};
		for (int i{0}; i < n; ++i) {
			l = -1;
			while (r - l > 1) {
				long long m{(l + r) / 2};
				if ((a[i] + b[m]) < x) l = m;
				else r = m;
			}
			sum += l + 1;
		}
		return sum;
	};

	long long l{2}, r{static_cast<long long>(2e9) + 1};
	while (r - l > 1) {
		long long m{(l + r) / 2};
		if (calc(m) < k) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
