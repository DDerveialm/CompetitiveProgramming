#include <iostream>

using namespace std;

bool check(int n, int x, int y, int t) {
	if ((t / x) + (t / y) >= n) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y;
	cin >> n >> x >> y, --n;
	int l{n / 2}, r{max(x, y) * n + 1};
	while (l < r - 1) {
		int m{(l + r) / 2};
		if (check(n, x, y, m - 1)) r = m;
		else l = m;
	}
	cout << l + min(x, y) << endl;
	return 0;
}
