#include <iostream>
#include <string>

#define fi first
#define se second

using namespace std;

pair<bool, int> calc_less(char c, int parity) {
	pair<bool, int> res;
	int x{c - '0'};
	if ((x-- & 1) == parity) res = {true, 1};
	else res = {false, 0};
	while (x >= 0)
		if ((x-- & 1) == parity) ++res.se;
	return res;
}

long long less_cnt(long long x) {
	string s{to_string(x)};
	long long res{1}, k{1};
	for (int i{static_cast<int>(s.size()) - 1}; i >= 0; --i) {
		auto c{calc_less(s[i], (i + 1) & 1)};
		if (c.fi) res += (c.se - 1) * k;
		else res = c.se * k;

		k *= 5;
	}
	k = 1;
	for (int i{1}; i < s.size(); ++i) 
		k *= 5, res += k;
	return res;
}

void solve() {
	long long L, R;
	cin >> L >> R;

	long long res{less_cnt(R) - less_cnt(L - 1)};
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}
