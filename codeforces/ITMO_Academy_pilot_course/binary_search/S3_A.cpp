#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

constexpr double err = 1e-6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& x : v) cin >> x.first >> x.second;

	auto check = [&v](double t) {
		pair<double, double> interval{-1e9, 1e9};
		for (auto& x : v) {
			double L = x.first - t * x.second;
			double R = x.first + t * x.second;
			if (interval.first < L) interval.first = L;
			if (interval.second > R) interval.second = R;
			if (interval.first > interval.second) return false;
		}
		return true;
	};
	double l{0 - err}, r{1e9}; // ans in (l:r]
	while (r - l >= 2 * err) {
		double m{(l + r) / 2};
		if (check(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(7) << (l + r) / 2 << endl;
	return 0;
}
