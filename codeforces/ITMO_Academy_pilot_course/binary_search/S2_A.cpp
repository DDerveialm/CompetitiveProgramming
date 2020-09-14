#include <iostream>
#include <cmath>

using namespace std;

bool check(long long w, long long h, long long n, long long x) {
	long long nr{x / w};
	long long nc{x / h};
	if (nr * nc >= n) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long w, h, n;
	cin >> w >> h >> n;
	long long l{1}, r{max(w, h) * static_cast<long long>(ceil(sqrt(n))) + 1};
	while (l < r - 1) {
		long long m{(l + r) / 2};
		if (check(w, h, n, m - 1)) r = m;
		else l = m;
	}
	cout << l << endl;
	return 0;
}
