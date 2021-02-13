#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int m, n;
	cin >> m >> n;
	vector<pair<int, int>> v(n);
	for (auto& [a, b] : v) cin >> a >> b;

	constexpr int max_b{4};
	using state_t = array<int, max_b>;

	auto trans = [](const state_t& old, int neww) {
		state_t res;
		res[0] = neww;
		for (int i{1}; i < max_b; ++i) res[i] = old[i - 1];
		return res;
	};
	auto avail = [&](const state_t& stat) {
		set<int> res{};
		for (int i{0}; i < n; ++i) res.insert(i);
		for (int i{0}; i < max_b; ++i)
			if (stat[i] != -1) {
				auto& [a, b]{v[stat[i]]};
				if (b > i) res.erase(stat[i]); // not available
			}
		return res;
	};

	map<state_t, int> last{}, curr{};
	auto add_state = [&curr](state_t n_stat, int val) { // to curr
		auto it{curr.find(n_stat)};
		if (it == curr.end()) curr.emplace(n_stat, val);
		else it -> second = max(it -> second, val);
	};
	state_t init; fill(init.begin(), init.end(), -1);
	last.emplace(init, 0);
	for (int t{1}; ; ++t) {
		for (auto& [stat, x] : last) {
			for (auto& i : avail(stat)) {
				auto& [a, b]{v[i]};
				if (x + a >= m) {
					cout << t << '\n';
					return ;
				}
				add_state(trans(stat, i), x + a);
			}
			add_state(trans(stat, -1), x);
		}
		last = move(curr);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
