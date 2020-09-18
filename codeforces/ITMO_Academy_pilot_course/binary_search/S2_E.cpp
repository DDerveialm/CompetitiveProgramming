#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

constexpr double err = 1e-6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double c;
	cin >> c;
	double l{0}, r{c}; // ans is in [l, r)
	while (l <= r - 2 * err) {
		double m{(l + r) / 2};
		if (pow(m, 2) + sqrt(m) <= c) l = m;
		else r = m;
	}
	cout << fixed << setprecision(7) << (l + r) / 2 << endl;
	return 0;
}
