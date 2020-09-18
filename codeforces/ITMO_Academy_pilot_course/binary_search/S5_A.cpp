#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long k;
	cin >> n >> k;
	vector<pair<long long, long long>> seg(n);
	for (auto& e : seg) cin >> e.first >> e.second;

	auto calc = [&seg](long long x) {
		long long sum{0};
		for (auto& e : seg)
			sum += max(0ll, min(x - e.first, e.second - e.first + 1));
		return sum;
	};

	long long l{static_cast<long long>(-2e9)}, r{static_cast<long long>(2e9) + 1};
	while (r - l > 1) {
		long long m{(l + r) / 2};
		if (calc(m) <= k) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
