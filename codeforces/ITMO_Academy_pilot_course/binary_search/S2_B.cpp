#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

constexpr double err = 1e-6;

bool check(const vector<double>& lopes, int k, double l) {
	int cnt{0};
	for (auto& x : lopes) cnt += x / l;
	if (cnt >= k) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<double> vec(n);
	for (auto& x : vec) cin >> x;
	double l{0}, r{*max_element(vec.begin(), vec.end()) + err}; // ans is in [l, r)
	while (l <= r - 2 * err) {
		double m{(l + r) / 2};
		if (check(vec, k, m)) l = m;
		else r = m;
	}
	cout << fixed << setprecision(7) << (l + r) / 2 << endl;
	return 0;
}
