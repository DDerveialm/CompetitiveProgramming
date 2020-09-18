#include <iostream>
#include <vector>

using namespace std;

constexpr double err = 1e-5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	vector<double> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	auto check = [&](double avg) {
		vector<double> p(n + 1);
		p[0] = 0;
		for (int i{1}; i <= n; ++i)
			p[i] = p[i - 1] + (v[i] - avg);

		vector<double> mx(n + 1);
		mx[n] = p[n];
		for (int i{n - 1}; i >= 0; --i)
			mx[i] = max(mx[i + 1], p[i]);

		for (int i{0}; i + d <= n; ++i)
			if (p[i] <= mx[i + d]) return i + 1;
		return 0;
	};

	auto get = [&](int i, double avg) {
		double tot{0}, sum{0};
		for (int j{i}; j <= n; ++j) {
			tot += v[j];
			sum += avg;
			if (j >= i + d - 1 && tot >= sum) return j;
		}
		return -1;
	};

	double l{0}, r{100 + err};
	while (r - l >= err) {
		double m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	int first{check(l)};
	int last{get(first, l)};
	cout << first << " " << last << endl;
	return 0;
}
