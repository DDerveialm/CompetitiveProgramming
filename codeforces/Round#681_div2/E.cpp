#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;

	vector<long long> fac{};
	fac.push_back(1);
	for (int i{1}; ; ++i) {
		fac.push_back(i * fac.back());
		if (fac.back() > 2e10) break;
	}
	int len{static_cast<int>(fac.size()) - 1};

	long long p{0};
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			long long sum{0};

			auto t{p};
			set<int> s{};
			for (int i{min(n, len)}; i >= 1; --i) s.insert(n - i + 1);
			for (int i{min(n, len)}; i >= 1; --i) {
				auto it{s.begin()};
				advance(it, t / fac[i - 1]);
				if (n - i + 1 >= l && n - i + 1 <= r) sum += *it;
				s.erase(it);
				t %= fac[i - 1];
			}

			r = min(r, n - len);
			if (r >= l) sum += static_cast<long long>(l + r) * static_cast<long long>(r - l + 1) / 2;

			cout << sum << '\n';
		} else if (op == 2) {
			int x;
			cin >> x;
			p += x;
			if (n <= len) p %= fac[n];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
