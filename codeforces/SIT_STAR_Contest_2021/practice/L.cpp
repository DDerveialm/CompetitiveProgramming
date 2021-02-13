#include <iostream>
#include <array>
#include <utility>

using namespace std;

template <typename T>
pair<T, T> operator- (const pair<T, T>& x, const pair<T, T>& y) {
	return {x.first - y.first, x.second - y.second};
}
template <typename T>
pair<T, T> operator* (const T& k, const pair<T, T>& p) {
	return {k * p.first, k * p.second};
}
template <typename T>
pair<T, T> extEuc(T X, T Y) {
	auto x{X}, y{Y};
	pair<T, T> p{1, 0}, q{0, 1};
	if (x < y) swap(x, y), swap(p, q); // let x >= y
	while (y) {
		auto n{p - (x / y) * q};
		auto r{x % y};	
		x = y, p = q;
		y = r, q = n;
	}
	return p;
}

long long func(long long a, long long b, long long c) { // ax + by = c
	auto [x, y]{extEuc(a, b)};
	auto gcd{a * x + b * y};
	if (c % gcd) return 0; // no solution

	x *= (c / gcd), y *= (c / gcd); // one of the solutions
	auto k1{b / gcd}, k2{a / gcd};
	x += (y / k2) * k1, y %= k2;
	if (y <= 0) x -= k1, y += k2; // make y >= 1

	return (x > 0 ? ((x + k1 - 1) / k1) : 0);
}

void solve() {
	long long x;
	cin >> x;

	long long ans{0};
	array<long long, 3> f{1, 1, 2};
	while (f[0] + f[1] <= x) {
		ans += func(f[0], f[1], x);

		f[0] = f[1], f[1] = f[2], f[2] = f[0] + f[1];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
