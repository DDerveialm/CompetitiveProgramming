#include <iostream>
#include <vector>
#include <set>
#include <functional> // std::greater
#include <optional>

using namespace std;

optional<vector<pair<int, int>>> check(multiset<int, greater<int>> ms, int x) {
	vector<pair<int, int>> res{};
	while (!ms.empty()) {
		int a{*ms.begin()}; ms.erase(ms.begin());
		auto b{ms.find(x - a)};
		if (b == ms.end()) return nullopt;

		res.emplace_back(a, *b), x = a, ms.erase(b);
	}
	return res;
}

void solve() {
	int n; cin >> n;
	multiset<int, greater<int>> ms{};
	for (int i{0}; i < 2 * n; ++i) {
		int x; cin >> x;
		ms.insert(x);
	}

	for (auto it{next(ms.begin())}; it != ms.end(); ++it) {
		auto x{*ms.begin() + *it}; // try all possibilities
		auto res{check(ms, x)};
		if (res) {
			cout << "YES\n" << x << '\n';
			for (auto& [a, b] : res.value()) cout << a << ' ' << b << '\n';
			return ;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
