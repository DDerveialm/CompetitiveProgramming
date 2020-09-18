#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s{};
	cin >> s;
	array<long long, 3> rcp{};
	for (auto& x : s)
		if (x == 'B') ++rcp[0];
		else if (x == 'S') ++rcp[1];
		else ++rcp[2];
	array<long long, 3> n{}, p{};
	for (auto& x : n) cin >> x;
	for (auto& x : p) cin >> x;
	long long m;
	cin >> m;

	auto check = [&](long long x) {
		long long c{max(0ll, x * rcp[0] - n[0]) * p[0] + max(0ll, x * rcp[1] - n[1]) * p[1] + max(0ll, x * rcp[2] - n[2]) * p[2]};
		if (c <= m) return true;
		else return false;
	};
	long long l{0}, r{static_cast<long long>(1e13)};
	while (l < r - 1) {
		long long m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
