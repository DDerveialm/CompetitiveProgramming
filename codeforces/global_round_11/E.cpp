#include <iostream>
#include <vector>

using namespace std;

template<typename T>
pair<T, T> operator* (T m, pair<T, T> p) {
	return {m * p.first, m * p.second};
}
template<typename T>
pair<T, T> operator- (pair<T, T> p1, pair<T, T> p2) {
	return {p1.first - p2.first, p1.second - p2.second};
}

pair<long long, long long> extEuc(long long x, long long y) {
	pair<long long, long long> p{1, 0}, q{0, 1};
	if (x < y) swap(x, y), swap(p, q);

	while (y) {
		auto n{p - (x / y) * q};

		x %= y, swap(x, y);
		p = q, q = n;
	}
	return p;
}

long long msb(int x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return (x + 1) >> 1;
}

namespace E {
	vector<string> ans{};

	void write_to_k_times(long long x, long long k) {
		long long t{1};
		while (t * 2 <= k) {
			ans.push_back(to_string(x * t) + " + "s + to_string(x * t));
			t *= 2;
		}
		long long m{t};
		while (t != k) {
			if (k - t >= m) {
				ans.push_back(to_string(x * t) + " + "s + to_string(x * m));
				t += m;
			}
			m /= 2;
		}
	}

	void solve() {
		ans.clear();
		long long x;
		cin >> x;
		write_to_k_times(x, msb(x));

		long long y{msb(x) * x};
		ans.push_back(to_string(y) + " ^ "s + to_string(x));
		y ^= x; // y = (msb(x) * x) ^ x

		auto p{extEuc(x, y)}; // linear combination of gcd(x, y)

		if (p.first < 0) { // Bezout's theorem
			if (p.first % 2) p.first -= y, p.second += x;
			p.first *= -1;
		} else {
			if (p.second % 2) p.first += y, p.second -= x;
			p.second *= -1;
		}
		write_to_k_times(x, p.first);
		write_to_k_times(y, p.second);
		x *= p.first;
		y *= p.second;

		ans.push_back(to_string(x) + " ^ "s + to_string(y));

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	E::solve();

	return 0;
}
