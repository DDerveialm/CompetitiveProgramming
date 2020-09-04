#include <iostream>

using namespace std;

int min_d(int n, int x, int y) {
	int t = y - x;
	int d = (t + n - 2) / (n - 1); // ceil(t / (n - 1))
	while (t % d) ++d;
	return d;
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	auto d = min_d(n, x, y);

	int i{0};
	for (; i < n; ++i) {
		auto a = y - i * d;
		if (a <= 0) break;
		cout << a << " ";
	}
	for (int j{1}; j <= n - i; ++j) cout << y + j * d << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
