#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, k;
	cin >> n >> k;

	auto calc = [&n](long long x) {
		long long sum{0};
		for (int i{1}; i <= n; ++i) sum += min((x - 1) / i, n);
		return sum;
	};

	long long l{1}, r{static_cast<long long>(1e10) + 1};
	while (r - l > 1) {
		long long m{(l + r) / 2};
		if (calc(m) < k) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
