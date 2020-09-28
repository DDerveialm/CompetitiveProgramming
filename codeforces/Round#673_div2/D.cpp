#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, s{0};
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, s += x;

	if (s % n) {
		cout << "-1\n";
		return ;
	}

	auto op = [&v](int i, int j, int x) {
		cout << i << ' ' << j << ' ' << x << '\n';
		v[i - 1] -= i * x;
		v[j - 1] += i * x;
	};

	cout << 3 * n - 3 << '\n';
	for (int i{2}; i <= n; ++i) {
		op(1, i, (i - v[i - 1] % i) % i);
		op(i, 1, v[i - 1] / i);
	}
	for (int i{2}; i <= n; ++i)
		op(1, i, s / n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
