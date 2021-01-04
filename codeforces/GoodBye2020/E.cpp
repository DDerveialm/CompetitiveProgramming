#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;
	constexpr ll p{static_cast<long long>(1e9) + 7};

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> cnt(60);
	for (auto& x : v) // v[i]
		for (int b{0}; b < 60; ++b)
			if (x & (1ll << b)) ++cnt[b];

	ll ans{0};
	for (auto& x : v) { // v[j]
		ll k{0};
		for (int b{0}; b < 60; ++b) {
			auto t{(1ll << b) % p};
			k += (t * (x & (1ll << b) ? n : cnt[b])) % p, k %= p;
		}

		for (int b{0}; b < 60; ++b) {
			if (!(x & (1ll << b))) continue;
			auto t{(1ll << b) % p};
			ans += ((cnt[b] * t) % p) * k, ans %= p;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
