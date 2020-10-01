#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

struct Info{int set, weight;};

class dsu {
private:
	vector<Info> v{};
public:
	dsu(int n) : v(n) {
		for (int i{0}; i < n; ++i) v[i] = {i, 1};
	}
	int get(int x) {
		if (x == v[x].set) return x;

		auto rx{get(v[x].set)};
		v[x].set = rx;
		return rx;
	}
	void unionn(int x, int y) {
		auto rx{get(x)}, ry(get(y));
		if (rx == ry) return ;

		if (v[rx].weight < v[ry].weight) swap(rx, ry);
		v[ry].set = rx;
		v[rx].weight += v[ry].weight, v[ry].weight = 0;
	}
};

void solve() {
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<pair<int, pair<int, int>>> e{};
	for (int i{0}; i < m; ++i) {
		int s;
		cin >> s;
		for (int j{0}; j < s; ++j) {
			int v;
			cin >> v, --v;
			e.emplace_back(a[i] + b[v], make_pair(n + i, v));
		}
	}
	sort(e.begin(), e.end(), greater<pair<int, pair<int, int>>>());

	dsu ds{n + m};
	long long ans{0};
	for (auto& x : e) {
		auto& u{x.second.first}, v{x.second.second};
		if (ds.get(u) == ds.get(v)) ans += x.first;
		else ds.unionn(u, v);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
