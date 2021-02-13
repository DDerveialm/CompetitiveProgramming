#include <iostream>
#include <array>

using namespace std;

class chessboard {
public:
	array<char, 9> m;
	array<int, 9> cr{};
	array<long long, 10> cnt{};

	void dfs(int p, int lb) {
		if (p >= 9) {
			++cnt[lb - 1];
			return ;
		}

		auto up = [](int _p) { return ((_p / 3) - 1 >= 0 ? _p - 3 : -1); };
		auto left = [](int _p) { return ((_p % 3) - 1 >= 0 ? _p - 1 : -1); };

		if (m[p] == '.') dfs(p + 1, lb);
		else {
			for (int i{1}; i < lb; ++i) {
				int flag{true};
				int t{up(p)};
				while (t != -1) {
					if (m[t] == '.') t = up(t);
					else { // in between
						if (cr[t] == i) flag = false;
						break;
					}
				}
				t = left(p);
				while (t != -1) {
					if (m[t] == '.') t = left(t);
					else {
						if (cr[t] == i) flag = false;
						break;
					}
				}
				if (flag) cr[p] = i, dfs(p + 1, lb);
			}
			cr[p] = lb, dfs(p + 1, lb + 1);
		}
	}	
};

void solve() {
	long long num;
	cin >> num;

	chessboard cb{};
	for (auto& x : cb.m) cin >> x;

	cb.dfs(0, 1);

	auto mod_ = [](long long& x) {
		x %= (static_cast<long long>(1e9) + 7);
	};
	auto nPr = [&mod_](long long n, long long r) {
		if (r > n) return 0ll;
		long long res{1};
		for (long long i{0}; i < r; ++i) mod_(res *= (n - i));
		return res;
	};

	long long ans{0};
	for (int i{0}; i <= 9; ++i) {
		mod_(ans += nPr(num, i) * cb.cnt[i]);
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
