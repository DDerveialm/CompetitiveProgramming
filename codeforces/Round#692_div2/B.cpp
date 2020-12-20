#include <iostream>
#include <array>

using namespace std;

bool check(long long x) {
	array<bool, 10> d{};
	auto t{x};
	while (t) {
		d[t % 10] = true;
		t /= 10;
	}
	for (int i{1}; i <= 9; ++i)
		if (d[i] && (x % i)) return false;
	return true;
}

void solve() {
	long long x;
	cin >> x;

	while (!check(x)) ++x;

	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
