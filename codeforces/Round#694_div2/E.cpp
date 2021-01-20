#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long que(int p) {
	long long res{0};
	cout << "? " << p + 1 << endl;
	cin >> res;
	return res;
}

void ans(int p) {
	cout << "! " << p + 1 << endl;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int t{static_cast<int>(sqrt(n))};
	if (n < 100) t = 1;

	for (int i{0}; i < t; ++i) que(0);

	int p{0};
	while (que(p) <= k) p += t;

	p = (p - 1 + n) % n;
	while (que(p) != k) p = (p - 1 + n) % n;

	ans(p);
}

void sim() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n, k);

	for (int j{0}; j < 2 * n; ++j) {
		vector<int> t(n, 0);
		for (int i{0}; i < n; ++i) {
			if (i != 0) t[(i - 1 + n) % n] += v[i] / 2, t[(i + 1) % n] += (v[i] + 1) / 2;
			else t[(i + 1) % n] += v[i];
		}
		swap(v, t);

		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
