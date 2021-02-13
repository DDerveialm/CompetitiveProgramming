#include <iostream>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	long long ans{0};
	ans += (n / 5) * 5;
	ans += (n / 3 - n / 15) * 3;
	ans += (n / 2 - n / 10 - n / 6 + n / 30) * 2;
	ans += (n - n / 2 - n / 3 - n / 5 + n / 6 + n / 10 + n / 15 - n / 30) * 1;

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
