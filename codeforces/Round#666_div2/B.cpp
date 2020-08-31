#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr long long MAX = 2e14;

long long diff(const vector<long long>& vec, int c) {
	long long d{0};
	long long a{1};
	for (int i{}; i < vec.size(); ++i) {
		d += abs(vec[i] - a);
		a *= c;
		if (d >= MAX) return MAX;
	}
	return d;
}

void solve() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	long long sum{0};
	for (auto& e : vec) cin >> e, sum += e;
	sort(vec.begin(), vec.end());

	int max_c {static_cast<int> (ceil(exp(log(vec.back() + sum - n) / (n - 1))))};
	long long min_d{MAX};
	for (int i{1}; i <= max_c; ++i) {
		auto d = diff(vec, i);
		if (d < min_d) min_d = d;;
	}
	cout << min_d << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();

	return 0;
}
