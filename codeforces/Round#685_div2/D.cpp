#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	long long d, k;
	cin >> d >> k;

	long long l{static_cast<long long>(floor(sqrt(d * d / 2)))};
	l = l / k * k;

	if ((l + k) * (l + k) + l * l <= d * d) cout << "Ashish\n";
	else cout << "Utkarsh\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
