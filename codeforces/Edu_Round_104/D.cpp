#include <iostream>

using namespace std;

unsigned long long Intsqrt(unsigned long long x) {
	unsigned long long l{0ULL}, r{1ULL << 32};
	while (r - l > 1) {
		auto m{(l + r) / 2};
		if (m * m <= x) l = m;
		else r = m;
	}
	return l;
}

void solve() {
	int n;
	cin >> n;

	int mxa{Intsqrt(2 * n - 1)}; // a^2 <= 2n - 1
	if (mxa >= 3) cout << (mxa - 3) / 2 + 1 << '\n';
	else cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
