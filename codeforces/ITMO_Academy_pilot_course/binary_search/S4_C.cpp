#include <iostream>
#include <vector>

using namespace std;

constexpr double err = 1e-5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<pair<double, double>> v(n + 1);
	for (auto& x : v) cin >> x.first >> x.second;

	auto check = [&v, &k](double avg) {
	};

	double l{1}, r{1e5 + err};
	while (r - l >= err) {
		double m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	return 0;
}
