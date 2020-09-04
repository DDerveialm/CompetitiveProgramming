#include <iostream>

using namespace std;

using ULL = unsigned long long;

ULL I;

int sum(ULL n) {
	ULL s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

ULL increase(ULL& n) {
	while (n % I == 0) I *= 10;
	auto add = I - n % I;
	n += add;
	return add;
}

void solve() {
	I = 10;

	ULL n;
	int s;
	cin >> n >> s;

	ULL ans{0};
	while (sum(n) > s) ans += increase(n);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
