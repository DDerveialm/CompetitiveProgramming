#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	auto check = [&](long long mx) {
		int i{0};
		for (int j{0}; j < k; ++j) {
			long long acc{0};
			while (i < n && acc + v[i] <= mx) acc += v[i++];
		}
		return i == n;
	};

	long long l{0}, r{accumulate(v.begin(), v.end(), 0ll)};
	while (r - l > 1) {
		long long m{(l + r) / 2};
		if (check(m)) r = m;
		else l = m;
	}

	cout << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
