#include <iostream>
#include <cmath>

using namespace std;

int msb(int x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x += 1;
	return (x >> 1);
}

void divide_conquer(int l, int r) {
	int m{(l + r) / 2};
	if (r - l > 2) {
		divide_conquer(l, m);
		divide_conquer(m, r);
	}
	for (int i{l}; i < m; ++i) cout << i << ' ' << i + (m - l) << '\n';
}

void solve() {
	int n, h;
	cin >> n;
	if (n <= 2) cout << "0\n";
	else {
		h = msb(n - 1);
		cout << 2 * (h / 2) * log2(h) << '\n';
		divide_conquer(1, h + 1);
		divide_conquer(n + 1 - h, n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
