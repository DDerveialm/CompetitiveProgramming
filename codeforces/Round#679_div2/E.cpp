#include <iostream>

using namespace std;

void solve() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	if (b * c < a) cout << "-1\n";
	else {
		auto k{a / (b * d)};
		cout << a * (k + 1) - k * (k + 1) / 2 * b * d << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
