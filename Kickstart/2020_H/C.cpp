#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> x(n), y(n);
	for (int i{0}; i < n; ++i)
		cin >> x[i] >> y[i];

	long long ansx{0}, ansy{0};
	sort(y.begin(), y.end());
	for (auto& e : y) ansy += abs(e - y[n / 2]);

	sort(x.begin(), x.end());
	for (int i{0}; i < n; ++i) x[i] -= i;
	sort(x.begin(), x.end());
	for (auto& e : x) ansx += abs(e - x[n / 2]);

	cout << ansx + ansy << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
